#include <print>
#include <vector>
#include <ranges>

struct MyType 
{
	int begin() { return 0; }
	int end()   { return 0; }
};

int main()
{
	MyType c;

	// #1. std::begin()
	auto p1 = std::begin(c);
	auto e1 = *p1; // compile-error. p1 은 반복자가 아닌 int

	auto p2 = std::begin(std::vector{1,2,3});
	auto e2 = *p2; // undefined behavior
				   

				   
	// #2. std::ranges::begin()
	auto p3 = std::ranges::begin(c);				 // error				   
	auto p4 = std::ranges::begin(std::vector{1,2,3});// error
}
