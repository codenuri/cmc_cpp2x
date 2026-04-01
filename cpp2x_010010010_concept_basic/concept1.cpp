#include <print>
#include <type_traits>	// C++11

template<typename T> 
void foo(const T& arg) {

	bool b1 = std::is_pointer<T>::value;	// C++11
	bool b2 = std::is_pointer_v<T>;			// C++17

	std::println("{}, {}", b1, b2);	
}

int main() {

	int n = 0;
	foo(n);		// false, false
	foo(&n);	// true,  true
}
