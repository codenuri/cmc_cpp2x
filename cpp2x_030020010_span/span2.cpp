#include <print>
#include <vector>
#include <span>

int main()
{
	std::vector v{1, 2, 3, 4, 5};
	int      x[5]{1, 2, 3, 4, 5};
	
	std::span<int> sp1{v};
	std::span<int> sp2{x};	
	std::span<int> sp3{x + 1, 3};
	std::span<int> sp4{v.data() + 1, 3};

	std::println("{}", sp1);	// [1, 2, 3, 4, 5]
	std::println("{}", sp2);	// [1, 2, 3, 4, 5]
	std::println("{}", sp3);	// [2, 3, 4]
	std::println("{}", sp4);	// [2, 3, 4]
}