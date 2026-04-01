#include <generator>
#include <print>

std::generator<int> range(int start, int end)
{
	for ( int i = start; i < end; ++i )
		co_yield i;
}

int main()
{
	for( auto n : range(1, 5) )
	{
		std::print("{}, ", n);	// 1, 2, 3, 4
	}
	std::println();
}