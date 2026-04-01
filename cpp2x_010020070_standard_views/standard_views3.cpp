#include <print>
#include <vector>
#include <ranges>

void p(std::ranges::view auto view)
{
	std::println("{}", view);	
}

int main() 
{
	std::vector v{1, 2, 3, 4, 5};
	
	p( v | std::views::as_rvalue );
	p( v | std::views::as_const );

	p( v | std::views::slide(2) ); 	// 인접한 N개씩 모아서 하나의 view 로 생성
									// [[1, 2], [2, 3], [3, 4], [4, 5]]      
	p( v | std::views::chunk(2) );  // [[1, 2], [3, 4], [5]]

	p( v | std::views::adjacent<2> ); // [(1, 2), (2, 3), (3, 4), (4, 5)]      
	p( v | std::views::adjacent_transform<2>([](int a, int b){ return a + b;} ) );
									 // [3, 5, 7, 9]
}