#include "task.h"

struct A 
{
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
	task.resume();
}
