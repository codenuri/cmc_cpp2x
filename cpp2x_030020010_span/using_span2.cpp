#include <print>
#include <vector>
#include <array>
#include <span>

void foo( std::span<int> sp )
{
	std::println("{}", sp[0]);		// 1
	std::println("{}", sp.front());	// 1
	std::println("{}", sp.back());	// 5
	std::println("{}", sp.size());	// 요소 갯수 5
	std::println("{}", sp.size_bytes()); // sizeof(int)*5
										 // => 20
}

int main()
{
	int x[5]{1, 2, 3, 4, 5};
	
	foo(x);
}
