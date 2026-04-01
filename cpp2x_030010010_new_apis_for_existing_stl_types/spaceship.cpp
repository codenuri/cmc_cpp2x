#include <print>
#include <vector>

int main()
{
	std::vector v1{1,2,3};
	std::vector v2{1,3,5};

	std::println("{}", std::is_eq(v1 <=> v2));
}