#include <print>
#include <coroutine>

#define log() { std::println("{}", __func__); }

class TaskPromise;

class Task 
{
public:
	using promise_type = TaskPromise;
    Task(const std::coroutine_handle<promise_type> coro) : coro{coro} {}
	std::coroutine_handle<promise_type> coro;
};

class TaskPromise 
{
public:
	Task get_return_object() { log(); return Task{std::coroutine_handle<TaskPromise>::from_promise(*this)}; }
	std::suspend_always initial_suspend() noexcept { log();return {}; }
	std::suspend_always final_suspend()   noexcept { log();return {}; }
	void return_void() {log();}
	void unhandled_exception() {log(); }
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

	std::println("main #1");
	task.coro.resume();
	
	std::println("main #2");
	task.coro.resume();

	if ( task.coro.done() )
	{
		task.coro.destroy();
	}
}













