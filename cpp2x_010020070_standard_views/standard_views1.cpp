#include <print>
#include <vector>
#include <ranges>

void p(std::ranges::view auto view)
{
	std::println("{}", view);	
}

int main() 
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	std::ranges::take_view tv1{v, 5};	// (1)
	auto tv2 = std::views::take(v, 5);	// (2)
	auto tv3 = v | std::views::take(5);	// (3)

	std::println("{}", tv3);	

	p( tv3 );

	p( v | std::views::take(5) );
}
