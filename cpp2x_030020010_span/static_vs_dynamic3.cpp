#include <print>
#include <vector>
#include <span>

int main()
{
	int      x[5]{1, 2, 3, 4, 5};
	std::vector v{1, 2, 3, 4, 5};

	std::span<int, 5> ss1{x}; 	// ok
	std::span<int, 5> ss2{v}; 	// ok
	
//	std::span<int, 3> ss3{x};	// error
	std::span<int, 3> ss4{v};	// UB(Undefined Behavior)

	std::span<int, 3> ss5{x, 3}; // ok
	std::span<int, 3> ss6{x, 4}; // UB(Undefined Behavior)
}

