#include <print>
#include <coroutine>
#include <utility>

class Task
{
public:
    struct promise_type
    {
		int value = 0;

		std::suspend_always yield_value(int v)
		{
			value = v;
			return {};
		}

        Task get_return_object() { return Task{ std::coroutine_handle<promise_type>::from_promise(*this) }; }
        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend()   noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };

    explicit Task(std::coroutine_handle<promise_type> coro) : coro{coro} {}
    std::coroutine_handle<promise_type> coro;
};

Task range(int start, int end)
{
	for( int i = start; i < end; i++)
		co_yield i;
}

int main()
{
    Task task = range(1, 10);
	
	task.coro.resume();

	while ( !task.coro.done() )
	{		
		std::print("{}, ", task.coro.promise().value );
		task.coro.resume();
    }	

	if ( task.coro.done() )
		 task.coro.destroy();
}
