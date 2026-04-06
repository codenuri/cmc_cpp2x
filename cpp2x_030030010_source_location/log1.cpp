#include <print>
#include <string_view>
#include <source_location>

void log(std::string_view msg, 	std::source_location loc = std::source_location::current() )
{
//	std::source_location loc = std::source_location::current();

    std::println("[{}:{}] {} - {}",	loc.file_name(),
									loc.line(),
									loc.function_name(),
									msg);
}

int main()
{
	log("deleted"); 
		
}
