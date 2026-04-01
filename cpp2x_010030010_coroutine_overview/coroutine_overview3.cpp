#include <generator>
#include <ranges>
#include <print>

std::generator<int> infinite()
{
	int i = 0;
	while(true)
		co_yield ++i;
}

int main()
{
	for( auto e : infinite() | std::views::take(5) )
	{
		std::print("{}, ", e);
	}
	std::println();

	auto v = infinite() 	
			 | std::views::take(5) 
			 | std::views::filter([](int n){ return n % 2 == 1; });

	for( auto e : v)
	{
		std::print("{}, ", e);
	}	
	std::println();
}