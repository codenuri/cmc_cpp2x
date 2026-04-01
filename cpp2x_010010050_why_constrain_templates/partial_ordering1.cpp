#include <print>
#include <concepts>

template<std::integral T>	
void foo(T a) {
	std::println("#1. std::integral");
}	

template<std::integral T> requires (sizeof(T) > 4)
void foo(T a) {
	std::println("#2. std::integral && sizeof(T) > 4");
}

int main() {

	foo(1);		// int        #1   
	foo(1ll);	// long long  #2  
}