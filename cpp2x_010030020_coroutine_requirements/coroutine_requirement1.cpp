#include <print>
#include <coroutine>

// compile - error

void foo()
{
	std::println("foo #1");

	co_await std::suspend_always{};

	std::println("foo #2");
}

int main()
{
	foo();
}
