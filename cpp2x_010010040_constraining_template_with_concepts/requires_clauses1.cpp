#include <type_traits>
#include <concepts>

template<typename T> requires true 
void f1(T a) {}

template<typename T> requires std::is_integral_v<T> 
void f2(T a) {}

template<typename T> requires std::integral<T> 
void f3(T a) {}

template<typename T> requires ( sizeof(T) > 4 )
void f4(T a) {}

template<typename T> requires (!std::integral<T>)
void f5(T a) {}

template<typename T> 
		requires (std::integral<T> && sizeof(T) > 2)
void f6(T a) {}

template<typename T> 
constexpr bool is_small_type() {
	return sizeof(T) < sizeof(void*) * 2;
}

template<typename T> requires ( is_small_type<T>() )
void f7(T a) {}

template<typename T> 
		requires requires(T& c) { 
			c.foo();
		}
void f8(T a) {}



int main() {

}
