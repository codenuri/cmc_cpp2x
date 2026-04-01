#include <print>
#include <coroutine>
#include <utility>

class Task
{
public:
    struct promise_type
    {
		int value = 0;

		void return_value(int v) { value = v; }

        Task get_return_object() { return Task{ std::coroutine_handle<promise_type>::from_promise(*this) };        }
        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend()   noexcept { return {}; }
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
		
	co_return 3;	
}

int main()
{
    Task task = foo();

	task.coro.resume();
    task.coro.resume();

	int ret = 0;

	if ( task.coro.done() )
	{
		ret = task.coro.promise().value;

		task.coro.destroy();
	}

	std::println("{}", ret);
}
