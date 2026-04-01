#include <print>
#include <coroutine>
#include <utility>

template<typename T>
class Generator
{
public:
    struct promise_type
    {
		T value{};

		std::suspend_always yield_value(T v)
		{
			value = std::move(v);
			return {};
		}

        Generator get_return_object() { return Generator{ std::coroutine_handle<promise_type>::from_promise(*this) }; }
        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend()   noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };

    explicit Generator(std::coroutine_handle<promise_type> coro) : coro{coro} {}
    std::coroutine_handle<promise_type> coro;
};

Generator<int> range(int start, int end)
{
	for( int i = start; i < end; i++)
		co_yield i;
}
int main()
{
    Generator<int> g = range(1, 10);
	
	g.coro.resume();

	while ( !g.coro.done() )
	{		
		std::print("{}, ", g.coro.promise().value );
		g.coro.resume();
    }
	if ( g.coro.done() )
		 g.coro.destroy();
}
