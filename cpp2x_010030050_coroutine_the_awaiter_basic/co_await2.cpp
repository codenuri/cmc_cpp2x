#include "task.h"

#define log() { std::println("[MyAwaiter] {}", __func__); }

struct MyAwaiter
{
	bool await_ready() const noexcept { log(); return false; }
	void await_suspend(std::coroutine_handle<>) const noexcept { log(); }
	void await_resume() const noexcept { log(); }
};

Task foo()
{
    std::println("foo #1");

//	co_await std::suspend_always{};	
//	co_await std::suspend_never{};	
	co_await MyAwaiter{};	

	std::println("foo #2");
}

int main()
{
    Task task = foo();

    task.resume();
    std::println("main");
    task.resume();
}

