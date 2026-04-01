#include <print>
#include <type_traits>
#include <string>

template<typename T>
concept C1 = true;

template<typename T>
concept C2 = sizeof(T) > 4;

template<typename T>
concept C3 = std::is_pointer_v<T>;

template<typename T>
concept C4 = !C3<T>;

template<typename T> 
constexpr bool is_small_type() {
	return sizeof(T) < sizeof(void*) * 2;
}

template<typename T>
concept C5 = is_small_type<T>();

template<typename T>
concept C6 = is_small_type<T>() && std::is_integral_v<T>;

int main() {

	std::println("{},{}", C1<int>, C1<double>); // T, T
	std::println("{},{}", C2<int>, C2<double>); // F, T
	std::println("{},{}", C3<int>, C3<int*>);   // F, T
	std::println("{},{}", C4<int>, C4<int*>);   // T, F
	std::println("{},{}", C5<int>, C5<std::string>);// T, F
	std::println("{},{}", C6<int>, C6<float>);  // T, F
}

