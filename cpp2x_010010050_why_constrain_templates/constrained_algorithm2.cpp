#include <print>
#include <vector>
#include <algorithm>
#include <concepts>

int main() {

	std::vector v = {1,3,5,7,9,2,4,6,8,10};

	std::sort(v.begin(), v.end()); // ok
	std::sort(v); // error

	std::ranges::sort(v.begin(), v.end()); 	// ok
	std::ranges::sort(v);	// ok	
}



/*
template< std::random_access_iterator I, 
		  std::sentinel_for<I> S,
          class Comp = std::ranges::less, 
		  class Proj = std::identity > requires std::sortable<I, Comp, Proj>
constexpr I sort( I first, S last, Comp comp = {}, Proj proj = {} );

template< std::ranges::random_access_range R, 
		  class Comp = ranges::less,
          class Proj = std::identity > requires std::sortable<ranges::iterator_t<R>, Comp, Proj>
constexpr ranges::borrowed_iterator_t<R> sort( R&& r, Comp comp = {}, Proj proj = {} );
*/
