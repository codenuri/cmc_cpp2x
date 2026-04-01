#include <print>
#include <concepts>

template<typename T>
concept C = std::integral<T> && sizeof(T) > 4;

template<std::integral T>
void foo(T a) {
	std::println("#1. std::integral");
}	

template<C T>
void foo(T a) {
	std::println("#2. std::integral && sizeof(T) > 4");
}

int main() {

	foo(1);		// #1
	foo(1ll);	// #2
}