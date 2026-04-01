#include <print>
#include <string>
#include <concepts>

template<typename T> 
concept container = requires(T& c) {

	std::begin(c);
	std::end(c);
};

struct A {
	int begin() { return 0; }
	int end()   { return 0; }
};

int main() {

	std::println("{}", container<int[5]> );	// true
	std::println("{}", container<A> );		// true
}