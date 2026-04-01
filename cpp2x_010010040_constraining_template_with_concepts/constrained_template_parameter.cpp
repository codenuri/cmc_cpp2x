#include <concepts>

void note() {

	// std::integral<>       : 인자가 1개인 concept
	// std::convertible_to<> : 인자가 2개인 concept
	bool b1 = std::integral<int>;
	bool b2 = std::convertible_to<int, bool>;
}

template<std::integral T> 
void f1(T a) { }

template<std::convertible_to<const char*> T> 
void f2(T a) { }

template<typename T> 
	requires std::convertible_to<const char*, T>
void f3(T a) { }


template<std::integral T> requires ( sizeof(T) > 4 )
void f4(T a) { }

int main() {

	f1(10);	
	f2("hello");	// ok
//	f2(10);			// error

//	f4(10);		// error int
	f4(10ll);	// ok    long long
}
