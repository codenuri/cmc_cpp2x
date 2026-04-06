#include <print>
#include <vector>
#include <array>
#include <span>

int main()
{
	int x[5]{1, 2, 3, 4, 5};

	// static extent span
	std::span<int, 5> ss{x};

	// dynamic extent span
	std::span<int>    					ds1{x};
	std::span<int, std::dynamic_extent> ds2{x};

}
