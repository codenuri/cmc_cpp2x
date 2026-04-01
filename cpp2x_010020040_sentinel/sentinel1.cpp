#include <print>
#include <vector>
#include <iterator>
#include <algorithm>
namespace rng = std::ranges;

int main() 
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	auto first = v.begin();
	auto last  = v.end();

	auto ret1 = rng::find(first, last, 3);

	std::counted_iterator ci{v.begin(), 5};
	
//	auto ret2 = rng::find(ci, 3); // error
	auto ret2 = rng::find(ci, std::default_sentinel, 3);

	std::println("{}", *ret1);
	std::println("{}", *ret2);
}
