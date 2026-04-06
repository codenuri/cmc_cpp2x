#include <print>
#include <vector>
#include <array>
#include <span>

int main()
{
	int      x[5]{1, 2, 3, 4, 5};
	std::vector v{1, 2, 3, 4, 5};
	
	std::span<int> sp1{x, 5};
	std::span<int> sp2{x, x+3};
	std::span<int> sp3{v.data(),  3};
	std::span<int> sp4{v.begin(), 3};
	std::span<int> sp5{v.begin(), v.end()};
	std::span<int> sp6{x};
	std::span<int> sp7{v};
	std::span sp8{x};
	std::span sp9{v};
}

void foo( std::span<int> sp) {}