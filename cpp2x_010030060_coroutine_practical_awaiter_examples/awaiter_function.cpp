#include "task.h"

struct MyAwaier 
{
	bool await_ready() const noexcept { return false; }
  	
//	void await_suspend(std::coroutine_handle<> h) {}
	bool await_suspend(std::coroutine_handle<> h) { return false; }


//	void await_resume() { }	
	int  await_resume() { return 3; }

	
};

Task foo()
{
	std::println("foo #1");

	int ret = co_await MyAwaier{};

	std::println("foo #2 : {}", ret);


}

int main()
{
	Task task = foo();

	task.resume();
	std::println("main");
	task.resume();
}