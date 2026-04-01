#include <print>
#include <concepts>

template<typename T>
void f1(T a) {
}

template<typename T> requires std::integral<T>
void f2(T a) {
}

int main() {
	
	f1(10); 	// ok
	f1(3.4); 	// ok

	f2(10); 	// ok
//	f2(3.4); 	// error
}

