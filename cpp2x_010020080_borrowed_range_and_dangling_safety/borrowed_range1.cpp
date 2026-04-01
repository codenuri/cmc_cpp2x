#include <print>
#include <string>
#include <string_view>
#include <ranges>
namespace rng = std::ranges;

int main()
{
//	auto p1 = rng::begin( std::string{"hello"} );// error 


	std::string s{"hello"};

	auto p2 = rng::begin( std::string_view{s} ); // ok
		

	std::println("{}", rng::borrowed_range<std::string>); // f
	std::println("{}", rng::borrowed_range<std::string_view>); // t
	std::println("{}", rng::borrowed_range<std::string&>); // t
}