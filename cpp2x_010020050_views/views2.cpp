#include <print>
#include <vector>
#include <concepts>

template<std::ranges::bidirectional_range T> 
class reverse_view 
{
	T& rng;	
public:
	reverse_view(T& r) : rng{r} {}

	auto begin() { return rng.rbegin();}
	auto end()   { return rng.rend();}
};

int main() 
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	reverse_view rv{v};

	for( auto e : rv ) 
	{
		std::print("{}, ", e);
	}
	std::println();
}