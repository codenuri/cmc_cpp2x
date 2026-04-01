#include <print>

auto swap1 = [](auto& a, auto& b) { 
					auto t = std::move(a);
					a = std::move(b);
					b = std::move(t);
			};

auto swap2 = []<typename T>(T& a, T& b) { 
					T t = std::move(a);
					a = std::move(b);
					b = std::move(t);
			};			

int main() {
	
	int    n = 1;
	double d = 2.1;

	swap1(n, d); // ok
//	swap2(n, d); // error	 
	swap2(n, n); // ok



	std::println("{}, {}", n, d);
}
