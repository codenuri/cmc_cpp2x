#include <print>
#include <string>
#include <concepts>
#include <ranges>

template<typename T> 
concept container = requires(T& c) {

	std::ranges::begin(c);
	std::ranges::end(c);
};

int main() {

	std::println("{}", container<int> );		// false
	std::println("{}", container<int[5]> );		// true
	std::println("{}", container<std::string>);	// true

	std::println("{}", std::ranges::range<int> );			// false
	std::println("{}", std::ranges::range<int[5]> );		// true
	std::println("{}", std::ranges::range<std::string>);	// true	
}


