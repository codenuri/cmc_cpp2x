#include <print>
#include <list>
#include <ranges>

int main() 
{
	auto rg = std::views::iota(1, 4); // [1, 2, 3]

	std::list s = {0};
	
	s.insert_range(s.begin(), rg); 
	std::println("{}", s);		// [1, 2, 3, 0]

	s.append_range(rg); 		// [1, 2, 3, 0, 1, 2, 3]
	std::println("{}", s);

	s.prepend_range(rg); 		// [1, 2, 3, 1, 2, 3, 0, 1, 2, 3]
	std::println("{}", s);

	s.assign_range(rg);
	std::println("{}", s);	 	// [1, 2, 3]
}

