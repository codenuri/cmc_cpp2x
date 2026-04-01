#include <print>
#include <vector>

int main()
{
	std::vector v{ 1, 2, 3, 4, 5, 6, 7 };

	for( auto e : v ) 
	{
		std::print("{}, ", e );
	}
	
	std::println();
}

