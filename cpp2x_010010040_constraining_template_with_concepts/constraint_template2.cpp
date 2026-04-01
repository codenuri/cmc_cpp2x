#include <print>
#include <concepts>
#include <type_traits>

template<typename T> 
std::enable_if_t<std::is_integral_v<T>>
f1(T a)  {
}

template<typename T> requires std::integral<T> 
void f2(T a) {
}


int main() {
	
}