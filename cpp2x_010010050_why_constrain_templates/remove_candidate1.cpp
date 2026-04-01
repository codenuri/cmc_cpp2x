#include <print>
#include <concepts>

template<typename T> 
void foo(T a) {
	auto ret = a % 3;
}

void foo(double a) {
	std::println("double");
}

int main() {

	foo(3.4f); // error
}