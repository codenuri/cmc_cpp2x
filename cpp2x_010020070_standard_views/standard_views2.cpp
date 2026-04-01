#include <print>
#include <vector>
#include <ranges>

void p(std::ranges::view auto view)
{
	std::println("{}", view);	
}

int main() 
{
	std::vector v{1, 2, 7, 4, 3, 6, 5};

	p( v | std::views::take(5) );		// [1, 2, 7, 4, 3]
	p( v | std::views::take_while([](int e){ return e < 5; }) ); // [1, 2] 

	p( v | std::views::drop(5) );		// [6, 5]
	p( v | std::views::drop_while([](int e){ return e < 5; }) ); // [7, 4, 3, 6, 5] 	 

	p( v | std::views::stride(2) );		// [1, 7, 3, 5]

	p( v | std::views::reverse );		// [5, 6, 3, 4, 7, 2, 1] 
	p( v | std::views::enumerate ); 	// [(0, 1), (1, 2), (2, 7), (3, 4), (4, 3), (5, 6), (6, 5)]
	p( v | std::views::filter([](int e)    { return e % 2 == 0; }) );	// [2, 4, 6]
	p( v | std::views::transform([](int e) { return e * 2; }) );		// [2, 4, 14, 8, 6, 12, 10]


	for ( auto [idx, value] : v | std::views::enumerate )
	{	
		std::println("{} : {}", idx, value);	// 0 : 1
												//   ~
												// 6 : 5
	}
}