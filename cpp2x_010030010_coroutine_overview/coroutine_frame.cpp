#include <print>
#include <generator>

std::generator<int> foo()
{
	int a = 1, b = 2;

	std::println("coroutine &a: {}", static_cast<void*>(&a));
	std::println("coroutine &b: {}", static_cast<void*>(&b));						   

	co_yield 1;
	a = 10;
	co_yield 2;
	a = 30;
}
void goo()
{
	int a = 1, b = 2;

	std::println("     goo  &a: {}", static_cast<void*>(&a));
	std::println("     goo  &b: {}", static_cast<void*>(&b));	
}
int main() 
{
	int a = 1, b = 2;

	std::println("     main &a: {}", static_cast<void*>(&a));
	std::println("     main &b: {}", static_cast<void*>(&b));

	goo();

	for( auto e : foo() ) {
		std::print("{}, ", e);
	}
}