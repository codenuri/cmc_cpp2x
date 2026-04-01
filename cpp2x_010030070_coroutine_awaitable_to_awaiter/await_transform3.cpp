#include <print>
#include <coroutine>
#include <utility>

class Task
{
public:
    struct promise_type
    {
		// logging 을 위한 await_trnsform
		template<typename T> 
		decltype(auto) await_transform(T&& awaiter) 
		{ 
			std::println("log await_transform");
			return std::forward<T>(awaiter);
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
	co_await std::suspend_always{};
	std::println("foo #2");
	co_await std::suspend_never{};
	std::println("foo #3");

}

int main()
{
    Task task = foo();

	task.coro.resume();
	std::println("main");
    task.coro.resume();
	task.coro.resume();

	if ( task.coro.done() )
		 task.coro.destroy();
}
