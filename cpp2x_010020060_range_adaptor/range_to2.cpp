#include <print>
#include <ranges>
#include <vector>
#include <set>

int main() 
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	auto s1 = v 
			| std::views::take(5) 	// 1, 2, 3, 4, 5
			| std::views::reverse 	// 5, 4, 3, 2, 1
			| std::views::filter([](int n) { return n % 2 == 0;} )	// 4, 2
			| std::ranges::to<std::set>();

	for ( auto e : s1 ) {
		std::print("{}, ", e);	// 2, 4
	}
	std::println();

	
	// 1 ~ 10 까지의 홀수를 가진 vector 만들기.	
    auto v1 = std::views::iota(1, 11)      // 1 ~ 10
              | std::views::filter([](int n) { return n % 2 == 1; })
              | std::ranges::to<std::vector>();

	for ( auto e : v1 )	{
		std::print("{}, ", e);	// 1, 3, 5, 7, 9
	}
	std::println();
}
