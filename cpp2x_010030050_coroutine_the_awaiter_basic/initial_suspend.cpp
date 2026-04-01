// task.h
#include <print>
#include <coroutine>
#include <utility>

class Task
{
public:
    struct promise_type
    {
       std::suspend_never initial_suspend() noexcept { return {}; }


		std::suspend_always final_suspend()   noexcept { return {}; }


		Task get_return_object() { return Task{ std::coroutine_handle<promise_type>::from_promise(*this) };        }
        void return_void() {}
        void unhandled_exception() {}
    };

    using handle_type = std::coroutine_handle<promise_type>;

public:
    explicit Task(handle_type coro) : coro{coro} {}

    ~Task()
    {
        if (coro)
            coro.destroy();
    }

    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;

    Task(Task&& other) noexcept
        : coro(std::exchange(other.coro, {}))
    {
    }

    Task& operator=(Task&& other) noexcept
    {
        if (this != &other)
        {
            if (coro)
                coro.destroy();

            coro = std::exchange(other.coro, {});
        }
        return *this;
    }

    void resume()
    {
        if (coro && !coro.done())
            coro.resume();
    }

    bool done() const
    {
        return !coro || coro.done();
    }

private:
    handle_type coro{};
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

	std::println("main");
    task.resume();
}

