#include <print>
#include <ranges>
#include <vector>

int main() 
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	std::ranges::take_view tv{v, 5};	

	for ( auto e : tv )
	{
		std::print("{}, ", e);
	}
	std::println();

}

