#include <print>
#include <coroutine>
#include <generator>
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

    std::coroutine_handle<promise_type> coro;
    Generator( std::coroutine_handle<promise_type> c ) : coro(c) {}
   
    ~Generator() { if ( coro ) coro.destroy();}


    class Iter 
    {
    public:
        void operator++() { coro.resume();	}
        const T& operator*() const { return coro.promise().value;	}
        bool operator==(std::default_sentinel_t) const
        {
            return !coro || coro.done();
        }

        explicit Iter(std::coroutine_handle<promise_type> coroutine) :
            coro{ coroutine }{}
    private:
        std::coroutine_handle<promise_type> coro;
    };

    Iter begin() { if (coro) { coro.resume(); } return Iter{ coro }; }

    std::default_sentinel_t end() { return {}; }
};

//Generator<int> range(int start, int end)
std::generator<int> range(int start, int end)
{
	for( int i = start; i < end; i++)
		co_yield i;
}

int main()
{
	for( auto e : range(1, 10) )
	{
		std::print("{}, ", e);
	}
}
