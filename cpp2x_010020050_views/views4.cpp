#include <print>
#include <vector>
#include <ranges>
#include <algorithm>
namespace rng = std::ranges;

int main() 
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	rng::take_view tv{v, 5};
	
	rng::sort(v);	// container
	rng::sort(tv);	// view

	
	std::counted_iterator ci{v.begin(), 5};

	rng::sort(v.begin(), v.end()); 	      // iterator pair
	rng::sort(ci, std::default_sentinel); // iterator-sentinel 
}