// C++26
#include <print>
#include <map>
#include <string>
#include <string_view>
#include <functional>

int main()
{
    std::map<std::string, int, std::less<>> m;

#ifdef __cpp_lib_associative_heterogeneous_insertion

    std::string_view key = "apple";

	m[key] = 100;   // C++26 heterogeneous operator[]]
    std::println("{}", m.at("apple"));

#else
	std::println("heterogeneous_insertion not support");
#endif
}