#include <print>
#include <ranges>
#include <vector>
#include <set>

int main() 
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	auto view = v | std::views::take(3);

	auto s1 = std::ranges::to<std::set>(view);

	auto s2 = v | std::views::take(3) | std::ranges::to<std::set>();
	
	for ( auto e : s2 )	{
		std::print("{}, ", e); // 1, 2, 3
	}
	std::println();
}
