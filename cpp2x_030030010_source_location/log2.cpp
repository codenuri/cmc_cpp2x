#include <print>
#include <string_view>
#include <source_location>

void log(std::string_view msg, std::source_location loc = std::source_location::current() )
{
    std::println("[{}:{}] {} - {}",	loc.file_name(), loc.line(), loc.function_name(), msg);
}

void warning_log1(std::string_view msg)
{
	std::print("warning ");
	
	log(msg);				// log(msg, std::source_location::current() )		
}

void warning_log2(std::string_view msg, std::source_location loc = std::source_location::current())
{
	std::print("warning ");
	
	log(msg, loc);				// log(msg, loc )		
}

int main()
{
//	warning_log1("deleted"); // warning_log1("deleted")
	warning_log2("deleted"); // warning_log2("deleted", std::source_location::current())
		
}