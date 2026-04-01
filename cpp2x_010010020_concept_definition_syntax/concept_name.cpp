#include <print>
#include <type_traits>
#include <concepts>

template<typename T>
concept container = requires(T& c) {
	c.begin();
	c.end();
};

int main() {
	
	bool b1 = container<int>;
	
	bool b2 = std::is_integral_v<int>;
	bool b3 = std::integral<int>;

	std::println("{}", b1);	// true
	std::println("{}", b2);	// true
}