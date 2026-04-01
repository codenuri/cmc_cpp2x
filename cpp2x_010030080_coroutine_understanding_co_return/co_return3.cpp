#include <coroutine>
#include <print>
#include <utility>
#include <exception>
#include <stdexcept>

// Task 변화
// 1. template 사용
// 2. RAII 사용
template<typename T>
struct Task
{
    struct promise_type
    {
        T value{};

		void return_value(T v) noexcept(std::is_nothrow_move_assignable_v<T>)
        {
            value = std::move(v);
        }

        std::exception_ptr exception;

        Task get_return_object() { return Task{ std::coroutine_handle<promise_type>::from_promise(*this)}; }
		
		std::suspend_always initial_suspend() noexcept { return {}; }

        std::suspend_always final_suspend() noexcept   { return {}; }



        void unhandled_exception() noexcept
        {
            exception = std::current_exception();
        }
    };

    using handle_type = std::coroutine_handle<promise_type>;

private:
    handle_type coro = nullptr;

public:
    Task() noexcept = default;

    explicit Task(handle_type h) noexcept
        : coro(h)
    {
    }

    ~Task()
    {
        if (coro)
        {
            coro.destroy();
        }
    }

    // 복사 금지
    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;

    // 이동 허용
    Task(Task&& other) noexcept
        : coro(other.coro)
    {
        other.coro = nullptr;
    }

    Task& operator=(Task&& other) noexcept
    {
        if (this != &other)
        {
            if (coro)
            {
                coro.destroy();
            }

            coro = other.coro;
            other.coro = nullptr;
        }
        return *this;
    }

    bool resume()
    {
        if (!coro || coro.done())
        {
            return false;
        }

        coro.resume();
        return !coro.done();
    }

    bool done() const
    {
        return !coro || coro.done();
    }

    T result()
    {
        if (!coro)
        {
            throw std::runtime_error("No coroutine.");
        }

        if (!coro.done())
        {
            throw std::runtime_error("Coroutine has not completed yet.");
        }

        if (coro.promise().exception)
        {
            std::rethrow_exception(coro.promise().exception);
        }

        return coro.promise().value;
    }
};

Task<int> foo()
{
	std::println("foo #1");
	co_await std::suspend_always{};
	std::println("foo #2");

    co_return 10;
}

int main()
{
    Task<int> t = foo();

    t.resume();   // foo #1
	std::println("main");
	t.resume();   // foo #2

    int result = t.result();

    std::println("{}", result); // 10
}