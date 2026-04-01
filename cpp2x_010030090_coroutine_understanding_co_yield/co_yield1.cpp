#include <print>
#include <coroutine>
#include <utility>

// co_yield 적용전 코드 

class Task
{
public:
    struct promise_type
    {
        Task get_return_object() { return Task{ std::coroutine_handle<promise_type>::from_promise(*this) }; }
        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend()   noexcept { return {}; }
        void return_void() {}
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
}
int main()
{
    Task task = foo();

	task.coro.resume();
    task.coro.resume();

	if ( task.coro.done() )
		 task.coro.destroy();
}

