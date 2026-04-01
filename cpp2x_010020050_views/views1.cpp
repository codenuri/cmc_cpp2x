#include <print>
#include <vector>

template<typename T> 
class take_view 
{
	T& rng;
	std::ptrdiff_t count;
public:
	take_view(T& r, std::ptrdiff_t cnt) 
		: rng{r}, count{cnt} {}

	auto begin() { return rng.begin();}
	auto end()   { return std::next(rng.begin(), count);}
};

int main() 
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	take_view tv{v, 3};

	for( auto e : tv ) 
	{
		std::print("{}, ", e);
	}
	std::println();
}