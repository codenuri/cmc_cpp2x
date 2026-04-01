#include <print>

auto add1 = [](auto a, auto b) { return a + b; };
auto add2 = []<typename T1, typename T2>(T1 a, T2 b) { return a + b; };

int main() {

	std::println("{}", add1(1, 2.2)); // 3.2
	std::println("{}", add1(1.2, 2)); // 3.2

	std::println("{}", add2(1, 2.2)); // 3.2
	std::println("{}", add2(1.2, 2)); // 3.2
}

