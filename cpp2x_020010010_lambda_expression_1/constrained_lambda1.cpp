#include <print>
#include <concepts>

auto f1 = []<typename T> requires std::integral<T>(T a){};

auto f2 = []<std::integral T>(T a) { };

auto f3 = [](auto a) requires std::integral<decltype(a)>{};

auto f4 = [](std::integral auto a) { };

int main() {

	f1(1);	// ok
	f2(1);	// ok
	f3(1);	// ok
	f4(1);	// ok
//	f1(1.2); // error
//	f2(1.2); // error
//	f3(1.2); // error
//	f4(1.2); // error
}

