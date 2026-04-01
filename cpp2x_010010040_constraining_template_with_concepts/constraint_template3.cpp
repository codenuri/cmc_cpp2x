#include <concepts>

// requires clause
template<typename T> requires std::integral<T> 
void f1(T a) {
}

// constrained template parameter
template<std::integral T> 
void f2(T a) {
}

// abbreviated function template
void f3(std::integral auto a) {
}


int main() {
	
}