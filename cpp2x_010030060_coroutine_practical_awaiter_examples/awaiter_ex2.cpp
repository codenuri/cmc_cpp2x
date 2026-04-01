#include <exception>
#include <thread>
#include <chrono>
#include <memory>
#include <optional>
#include <string>
#include "task.h"
using namespace std::chrono_literals;

struct SharedState
{
	int a = 0;
	int b = 0;
	std::optional<int> result;
	std::exception_ptr eptr;
};

struct AsyncAddAwaiter
{
    std::shared_ptr<SharedState> state;

    AsyncAddAwaiter(int x, int y)
        : state(std::make_shared<SharedState>())
    {
        state->a = x;
        state->b = y;
    }

    bool await_ready() const noexcept { return false; }

    void await_suspend(std::coroutine_handle<> h)
    {
        auto s = state;
        std::thread([s, h]()
        {
            try
            {
                std::this_thread::sleep_for(1s);

                if (s->a < 0 || s->b < 0)
                    throw std::runtime_error("negative input is not allowed");

                s->result = s->a + s->b;
            }
            catch (...)
            {
                s->eptr = std::current_exception();
            }
            std::println("  [thread ] calculation done -> resume()");
            
			h.resume();
        }).detach();
    }

    int await_resume()
    {
        if (state->eptr)
            std::rethrow_exception(state->eptr);

        return *state->result;
    }
};

Task success_case()
{
    std::println("[success_case] before co_await");

    int value = co_await AsyncAddAwaiter{10, 20};

    std::println("[success_case] result = {}", value);
}


Task failure_case()
{
    std::println("[failure_case] before co_await");

    try
    {
        int value = co_await AsyncAddAwaiter{-10, 20};
        std::println("[failure_case] result = {}", value);
    }
    catch (const std::exception& e)
    {
        std::println("[failure_case] exception = {}", e.what());
    }
}

int main()
{
    Task t1 = success_case();
    Task t2 = failure_case();

    t1.resume();
    t2.resume();

    std::this_thread::sleep_for(2s);
}

