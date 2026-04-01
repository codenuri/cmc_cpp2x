#include <print>
#include <type_traits>
#include <string>

// T vs T&
template<typename T> 
concept C1 = requires(T c) {
	requires sizeof(c) > 10;
};

template<typename T>
concept C2 = requires(T& c) {
	requires sizeof(c) > 10;
};

int main() {

	std::println("{}", C1<int[10]>); // false
	std::println("{}", C2<int[10]>); // true
}
