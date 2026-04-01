#include <print>
#include <coroutine>
#include <generator>
#include <utility>

std::generator<int> range(int start, int end)
{
	for( int i = start; i < end; i++)
		co_yield i;
}

int main()
{
	for( auto e : range(1, 10) )
	{
		std::print("{}, ", e);
	}
	std::println();
	//-----------------------------------
	std::generator<int> g = range(1, 10);

	auto first = g.begin(); // 이순간 최초 resume() 
	auto last  = g.end();

	while( first != last )
	{
		std::print("{}, ", *first); // promise().value
		++first;	// resume()
	}
}
