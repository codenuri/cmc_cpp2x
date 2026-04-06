#include <print>
#include <vector>
#include <array>
#include <span>

int main()
{
	int x1[5]{1, 2, 3, 4, 5};
	int x2[3]{1, 2, 3};

	std::span<int, 5> ss{x1};
	std::span<int>    ds{x1};

	std::println("{}", sizeof(ss)); // 8
	std::println("{}", sizeof(ds)); // 16

	ds = x2; // ok 
//	ss = x2; // error

	ds = ss; // ok    dynamic_extent = static_extent
//	ss = ds; // error static_extent  = dynamic_extent

	ss = std::span<int, 5>(ds.data(), 5); // ok
}
