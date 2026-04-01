#include <concepts>
#include <string>
#include <print>
#include <type_traits>

int main()
{
	// same_as<T, U>
	std::println("{}", std::same_as<int, int>);			// true
	std::println("{}", std::same_as<int, double>);		// false

	std::println("{}", std::same_as<int, int&>);		// false
	std::println("{}", std::same_as<int, const int>);	// false

	using T = const int&;
	// T 가 int 계열인지 알고 싶다
	std::println("{}", std::same_as<int, std::decay_t<T>>); // true
									  // ^ T 에서 const, volatile, reference 를
									  //   제거한 타입 구할때 사용. type_traits 기술	
									  
	// derived_from<Derived, Base>
	class Base{};
	class Derived : public Base {};
	std::println("{}", std::derived_from<Derived, Base>);	// true
	std::println("{}", std::derived_from<Derived&, Base>);	// false


	// convertible_to<T, U>
	std::println("{}", std::convertible_to<Derived, Base>);	// true
	std::println("{}", std::convertible_to<int, double>);	// true
	std::println("{}", std::convertible_to<double, int>);	// true
	std::println("{}", std::convertible_to<const char*, std::string>);	// true
	std::println("{}", std::convertible_to<std::string, const char*>);	// false
	std::println("{}", std::convertible_to<int,  int&>);		// false
	std::println("{}", std::convertible_to<int,  const int&>);	// true
	std::println("{}", std::convertible_to<int&, int>);			// true

	// integral, floating_point
	std::println("{}", std::integral<int>);			// true
	std::println("{}", std::integral<int&>);		// false
	
	std::println("{}", std::signed_integral<int>);	// true
	std::println("{}", std::unsigned_integral<int>);// false
	
	std::println("{}", std::floating_point<int>);	// false
	std::println("{}", std::floating_point<double>);// true	
}
