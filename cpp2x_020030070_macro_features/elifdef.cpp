#include <print>

#define LINUX

int main()
{
	#ifdef WINDOWS
		std::println("WINDOWS");
	#elifdef LINUX
		std::println("LINUX");
	#else 
		std::println("OTHER");
	#endif 
}

