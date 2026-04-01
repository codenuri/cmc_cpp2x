#include <concepts>

template<typename T> 
void f1(T a) {

	auto ret = a % 3;
}

template<std::integral T> 
void f2(T a) {
	
	auto ret = a % 3;
}

int main() {

	f1(3.4);
	f2(3.4);
}
