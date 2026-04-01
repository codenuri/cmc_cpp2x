#include "task.h"

Task foo()
{
    std::println("foo #1");

//	co_await std::suspend_always{};	// 항상 suspend 해달라
	co_await std::suspend_never{};	// suspend 하지말라
	
	std::println("foo #2");
}
int main()
{
    Task task = foo();

    task.resume();
    std::println("main");
//	task.resume();
}

