#include <vector>
#include <print>
#include <algorithm>

int main() 
{
	std::vector v{1, 2, 3, 1, 2, 3, 1, 2, 3, 1};

	auto ret = std::ranges::remove(v, v.front());

	v.erase(ret.begin(), ret.end());

	for( auto e : v )
	{
		std::print("{}, ", e);
	}
	std::println();
}

