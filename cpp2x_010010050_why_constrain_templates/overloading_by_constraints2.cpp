#include <concepts>

template<typename T> void f1(T a) {}	
template<typename T> void f1(T a) {} // error

template<std::integral T>		
void f2(T a) {}		// #1

template<std::floating_point T>
void f2(T a) {}		// #2

int main() {

	f2(1);		// #1
	f2(1.2);	// #2

}
