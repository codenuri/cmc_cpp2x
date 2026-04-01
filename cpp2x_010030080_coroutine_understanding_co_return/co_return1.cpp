#include <print>
#include <coroutine>
#include <utility>

#define log() { std::println("{}", __func__); }

class Task
{
public:
    struct promise_type
    {
        Task get_return_object() { return Task{ std::coroutine_handle<promise_type>::from_promise(*this) };        }
        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend()   noexcept { log(); return {}; }
        void return_void() { log();  }
        void unhandled_exception() {}
    };

    explicit Task(std::coroutine_handle<promise_type> coro) : coro{coro} {}
    std::coroutine_handle<promise_type> coro;
};

Task foo()
{
    std::println("foo #1");
	co_await std::suspend_always{};
	std::println("foo #2");
		
	co_return 3;	// error.
					// promise_type 에 return_value() 없음	
}

int main()
{
    Task task = foo();

	task.coro.resume();
    task.coro.resume();

	if ( task.coro.done() )
		 task.coro.destroy();
}
