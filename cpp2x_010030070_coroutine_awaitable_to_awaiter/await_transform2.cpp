#include <print>
#include <coroutine>
#include <utility>
#include <chrono>
#include <thread>
using namespace std::literals;


struct SleepAwaiter 
{
	std::chrono::seconds delay;

	bool await_ready() const noexcept { return false; }

    void await_suspend(std::coroutine_handle<> h) 
	{
		auto d = delay;
        std::thread t( [h, d]() { 
			std::this_thread::sleep_for(d);
			h.resume(); 
		} );
		
		t.detach();
    }
    void await_resume() {}
};

class Task
{
public:
    struct promise_type
    {
		SleepAwaiter await_transform(std::chrono::seconds s) 
		{ 
			return SleepAwaiter{s}; 
		}

        Task get_return_object() { return Task{ std::coroutine_handle<promise_type>::from_promise(*this) };        }
        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend()   noexcept { return {}; }
        void return_void() { }
        void unhandled_exception() {}
    };
    explicit Task(std::coroutine_handle<promise_type> coro) : coro{coro} {}
    std::coroutine_handle<promise_type> coro;
};

Task foo()
{
    std::println("foo #1");
	
	co_await 1s;	// co_await SleepAwaiter{1s}

	std::println("foo #2");

}

int main()
{
    Task task = foo();

	task.coro.resume();
	std::println("main");
    task.coro.resume();

	if ( task.coro.done() )
		 task.coro.destroy();
}
