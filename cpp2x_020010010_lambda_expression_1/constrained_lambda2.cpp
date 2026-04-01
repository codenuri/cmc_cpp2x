#include <print>
#include <concepts>

auto swap = [](auto& a, auto& b) requires std::same_as<decltype(a), decltype(b)> { 
					auto t = std::move(a);
					a = std::move(b);
					b = std::move(t);
			};

int main() {
	
	int    n = 1;
	double d = 2.1;

	swap(n, n); // ok
//	swap(n, d); // error

	std::println("{}, {}", n, d);
}
