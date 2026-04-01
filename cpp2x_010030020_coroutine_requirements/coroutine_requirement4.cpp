#include <print>
#include <coroutine>

class Task 
{
public:
   	class promise_type 
	{
	public:
        Task get_return_object() { return Task{std::coroutine_handle<promise_type>::from_promise(*this)}; }
        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend()   noexcept { return {}; }
		void return_void() {}
        void unhandled_exception() { }
    };
    Task(const std::coroutine_handle<promise_type> coro) : coro{coro} {}

	std::coroutine_handle<promise_type> coro;
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













