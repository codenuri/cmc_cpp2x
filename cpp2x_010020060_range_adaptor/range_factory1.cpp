#include <print>
#include <ranges>
#include <vector>

int main() 
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};
	
	std::ranges::take_view v1{v, 5};
	std::ranges::iota_view v2{1, 6};

	auto v3 = std::views::take(v, 5);
	auto v4 = std::views::iota(1, 6);

	for ( auto e : v2 ) 
	{
		std::print("{}, ", e);	
	}
	std::println();
}
