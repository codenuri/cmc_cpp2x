#include <print>
#include <span>

void foo(std::span<int> sp)
{
	std::span sp1 = sp.first(3);
	std::span sp2 = sp.last(3);
	std::span sp3 = sp.subspan(2); 	  // offset
	std::span sp4 = sp.subspan(2, 2); // offset, count

	std::println("{}", sp1);	// [1, 2, 3]
	std::println("{}", sp2);	// [3, 4, 5]
	std::println("{}", sp3);	// [3, 4, 5]
	std::println("{}", sp4);	// [3, 4]
}

int main()
{
	int x[5]{1, 2, 3, 4, 5};
	
	foo(x);
}
