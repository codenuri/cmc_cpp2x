#include <print>

constexpr int foo(int a, int b) 
{ 
//	if ( std::is_constant_evaluated() )
	if not consteval
	{
		return a * b;
	}

	return a + b;
}

int main()
{
	int a = 2;
	int b = 5;

	constexpr int n1 = foo(2, 5);	// compile-time
	int n2 = foo(a, b);				// runtime

	std::println("{}", n1); // 10
	std::println("{}", n2);	// 7
}
