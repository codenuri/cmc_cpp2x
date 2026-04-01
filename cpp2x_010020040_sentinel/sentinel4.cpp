#include <print>
#include <vector>
#include <iterator>
#include <algorithm>
#include <concepts>
namespace rng = std::ranges;

int main() 
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	std::counted_iterator ci{v.begin(), 5};

//	auto a1 = std::find(ci, std::default_sentinel, 3); // error
	auto a2 = rng::find(ci, std::default_sentinel, 3); // ok


	using ITER = decltype(ci);

	bool b = std::sentinel_for<std::default_sentinel_t, ITER>;

	std::println("{}", b);
}









// C++98 find
// template<typename IT, typename T>
// IT find( IT first, IT last, const T& value );

// C++20 find
// template< std::input_iterator I, std::sentinel_for<I> S,
//          class T, class Proj = std::identity >
// requires std::indirect_binary_predicate
//             <ranges::equal_to, std::projected<I, Proj>, const T*>
// constexpr I find( I first, S last, const T& value, Proj proj = {} );
