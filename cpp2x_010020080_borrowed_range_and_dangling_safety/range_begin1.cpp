#include <print>
#include <vector>
#include <ranges>

int main()
{
	std::vector c{1, 2, 3, 4, 5};

	auto p1 = c.begin();
	auto p2 = std::begin(c);
	auto p3 = std::ranges::begin(c);
}
