#include <print>
#include <coroutine>

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
	Task get_return_object() { return Task{std::coroutine_handle<TaskPromise>::from_promise(*this)}; }
	std::suspend_always initial_suspend() noexcept { return {}; }
	std::suspend_always final_suspend()   noexcept { return {}; }
	void return_void() {}
	void unhandled_exception() { }
};
Task foo()
{

	int a = 1, b = 2; 
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
	if ( task.coro.done() ) task.coro.destroy();
}


