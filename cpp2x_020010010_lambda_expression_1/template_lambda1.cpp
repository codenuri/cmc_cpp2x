#include <print>

auto add1 = [](int  a, int  b) { return a + b; };
auto add2 = [](auto a, auto b) { return a + b; };

int main() {

	std::println("{}", add1(1, 2)    ); // 3
	std::println("{}", add1(1.2, 2.1)); // 3

	std::println("{}", add2(1, 2)    ); // 3
	std::println("{}", add2(1.2, 2.1)); // 3.3
	std::println("{}", add2(1.2, 2  )); // 3.2
	std::println("{}", add2(1,   2.1)); // 3.1
}

