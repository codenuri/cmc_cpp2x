#include <print>
#include <vector>
#include <ranges>
#include <algorithm>
namespace rng = std::ranges;

int main()
{
//	auto p1 = rng::begin( std::vector{1,2,3} );	// error.

	auto p2 = rng::find( std::vector{1,2,3}, 2);// ok

	auto e = *p2; // error. 
				  // iterator 가 아닌 dangling



	std::println("{}", typeid(p2).name() );
}
