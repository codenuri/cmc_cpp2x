#include <print>
#include <source_location>

void ex1()
{
	std::println("file     : {}", __FILE__);
	std::println("line     : {}", __LINE__);	
	std::println("function : {}", __func__);
}
void ex2()
{
//       1         2         3         4         5         6
//34567890123456789012345678901234567890123456789012345678901
    std::source_location loc = std::source_location::current();

	std::println("file     : {}", loc.file_name());
	std::println("line     : {}", loc.line());
	std::println("column   : {}", loc.column());
	std::println("function : {}", loc.function_name()); 
}
int main()
{
	ex1();
    ex2();
}
