#include <print>
#include <vector>
#include <map>
#include <ranges>

void p(std::ranges::view auto view)
{
	std::println("{}", view);	
}

int main() 
{
	// factories
	p( std::views::iota(1, 10) );	// [1, 2, 3, 4, 5, 6, 7, 8, 9]

	p( std::views::single(3) );		// [3]

	p( std::views::empty<int> );	// []

	p( std::views::repeat(7) | std::views::take(5) );	// [7, 7, 7, 7, 7]
}