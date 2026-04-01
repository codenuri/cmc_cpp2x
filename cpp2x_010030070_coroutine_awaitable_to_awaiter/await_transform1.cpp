#include <print>
#include <coroutine>
#include <utility>

class Task
{
public:
    struct promise_type
    {
		std::suspend_always await_transform(int n) { return {}; }

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

	co_await 3;
	
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
