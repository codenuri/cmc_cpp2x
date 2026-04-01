#include <print>
#include <vector>
#include <ranges>
namespace rng = std::ranges;

template<rng::range T>
void check(T c)
{
	std::println("{}", std::ranges::borrowed_range<T> );
}

int main()
{
	std::vector v{1, 2, 3, 4, 5};
	check(v);	// false

	check( rng::take_view{v, 5} );  // true
	check( rng::reverse_view{v} );  // true
	check( rng::reverse_view{std::vector{1,2,3}} );  // false
	check( rng::filter_view{ v, 
					[](int n){ return n % 2 == 1;} } ); // false
}