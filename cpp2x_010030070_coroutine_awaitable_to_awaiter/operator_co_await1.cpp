#include "task.h"

struct A 
{
	std::suspend_always operator co_await() 
	{
		return {};
	}
};

Task foo()
{
    std::println("foo #1");
	
	co_await A{};

	std::println("foo #2");	
}



int main()
{
    Task task = foo();

	task.resume();
	std::println("main");
	task.resume();
}
