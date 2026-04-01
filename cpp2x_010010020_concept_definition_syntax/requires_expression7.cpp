#include <print>
#include <type_traits>
#include <string>

// Template 인자가 2개인 concept

template<typename T, typename U>
concept convertible_to = requires(T from, U to) {
	static_cast<U>(from);
};

int main() {

	std::println("{}", convertible_to<const char*, std::string>);	// true
	std::println("{}", convertible_to<std::string, const char*>);	// false
}
