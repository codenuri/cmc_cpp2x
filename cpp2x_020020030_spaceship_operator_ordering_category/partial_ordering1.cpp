#include <print>

int main() 
{
	double NaN = 0.0 / 0.0;
	
	std::println("{}", NaN <  3.4 );	// false
	std::println("{}", NaN >  3.4 );	// false
	std::println("{}", NaN <= 3.4 );	// false
	std::println("{}", NaN >= 3.4 );	// false
	std::println("{}", NaN == 3.4 );	// false
	std::println("{}", NaN != 3.4 );	// true

	auto ret1 = 3.1 <=> 3.2;

	std::println("{}", typeid(ret1).name());
}
