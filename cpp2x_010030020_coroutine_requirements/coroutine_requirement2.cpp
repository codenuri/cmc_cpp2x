#include <print>
#include <coroutine>

// compile-error

class Task 
{
public:
	class promise_type 
	{
	};
};


Task  foo()
{
	std::println("foo #1");

	co_await std::suspend_always{};
	
	std::println("foo #2");	
}

int main()
{
	foo();
}
