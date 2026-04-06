#include <print>
#include <vector>
#include <array>
#include <span>

void foo(std::span<int> sp)
{
	std::println("{}", sp);
}

int main()
{
	std::vector v{1, 2, 3, 4, 5};
	std::array  a{1, 2, 3, 4, 5};
	int      x[5]{1, 2, 3, 4, 5};
	
	foo(v);
	foo(a);
	foo(x);

	foo(std::span{v.data() + 1, 3});
	foo(std::span{a.data() + 1, 3});
	foo(std::span{x + 1, 3});	
}
