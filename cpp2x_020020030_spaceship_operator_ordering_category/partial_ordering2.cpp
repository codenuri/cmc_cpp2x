#include <print>

int main() 
{
	double NaN = 0.0 / 0.0;

	auto ret = 3.1 <=> NaN;

	if ( ret > 0 )  { std::println("ret > 0");} 
	if ( ret < 0 )  { std::println("ret < 0");} 
	if ( ret == 0 ) { std::println("ret == 0");} 

	if ( ret == std::partial_ordering::unordered ) 
	{ 
		std::println("unordered");
	} 
}
