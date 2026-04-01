#include <print>
#include <compare>

int main()
{
	int a = 3;
	int b = 5;

	std::println("{}", (a <=> b) == 0);		// false
	std::println("{}", std::is_eq(a <=> b));// false	

	std::println("{}", std::is_neq (a <=> b));	// (a <=> b) != 0
	std::println("{}", std::is_lt  (a <=> b));	// (a <=> b) < 0
	std::println("{}", std::is_lteq(a <=> b));	// (a <=> b) <= 0
	std::println("{}", std::is_gt  (a <=> b));	// (a <=> b) > 0
	std::println("{}", std::is_gteq(a <=> b));	// (a <=> b) >= 0
}
