#include <print>
#include <vector>
#include <iterator>

int main() 
{
	std::vector v{ 1,2,3,4,5,6,7};

	auto it = v.begin();

	std::counted_iterator ci{it, 5};

	++it; 
	++ci;

	std::println("{}", *it); //	2
	std::println("{}, {}", *ci, ci.count()); // 2, 4

	while (ci.count() != 0) {
		std::print("{}, ", *ci++);
	}
	
//	++ci;					 // undefined
//	std::println("{}", *ci); // undefined 
}