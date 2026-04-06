#include <print>
#include <vector>
#include <span>

void foo(std::span<int, 5> sp) { }

int main()
{
	int      x[5]{1, 2, 3, 4, 5};
	std::vector v{1, 2, 3, 4, 5};

	std::span<int, 5> ss1{x};
	std::span<int, 5> ss2 = x;

	std::span<int, 5> ss3{v};
//	std::span<int, 5> ss4 = v; // error
	std::span<int, 5> ss4 = std::span<int, 5>{v};

	foo(x);
//	foo(v); // error
	foo(std::span<int, 5>{v}); // ok	
}

