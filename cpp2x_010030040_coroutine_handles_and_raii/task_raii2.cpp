#include <print>
#include <coroutine>
#include <utility>

class Task
{
public:
    struct promise_type
    {
        Task get_return_object()
        {
            return Task{ std::coroutine_handle<promise_type>::from_promise(*this) };
        }

        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend()   noexcept { return {}; }
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
    Task task1 = foo();

//	Task task2 = task1; // error
	Task task3 = std::move(task1); // ok

    std::println("main #1");
    task3.resume();

    std::println("main #2");
    task3.resume();

    if (task3.done())
    {
        std::println("coroutine finished");
    }
}