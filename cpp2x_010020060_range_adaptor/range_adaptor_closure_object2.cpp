#include <print>
#include <ranges>
#include <vector>
namespace rng = std::ranges;
namespace vw  = std::views;
int main() 
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	// filter_view -> reverse_view -> take_view -> vector
	// #1. using direct view class 
	rng::take_view    tv{v,  5};
	rng::reverse_view rv{tv};
	rng::filter_view  v1{rv, [](int n) { return n % 2 == 0;}};

	// #2. RAO
	auto v2 = vw::filter(vw::reverse(vw::take(v, 5)), [](int n) { return n % 2 == 0;} );
	
	// #3. RACO & Pipeline
	auto v3 = v | vw::take(5) | vw::reverse | vw::filter([](int n) { return n % 2 == 0;} );


	for ( auto e : v3 )
	{
		std::print("{}, ", e);
	}
	std::println();
}
