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

	std::counted_iterator ci{v.begin(), 5};

	rng::sort(first, last);
	rng::sort(ci,    std::default_sentinel);

	if ( ci == std::default_sentinel ) {}
	// operator==(ci, std::default_sentinel )
}
