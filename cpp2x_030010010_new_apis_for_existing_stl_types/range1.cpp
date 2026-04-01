#include <print>
#include <vector>
#include <ranges>

int main() 
{
	std::vector v1{1,2,3,4,5};

	auto range = v1 | std::views::take(3) 
				    | std::views::reverse;

	std::vector v2(v1);    // ok
//	std::vector v3(range); // error
	std::vector v4(std::from_range, range); // ok
	
	std::println("{}", v4); // [3, 2, 1]
}

