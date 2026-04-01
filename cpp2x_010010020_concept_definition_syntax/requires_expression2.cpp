#include <print>
#include <type_traits>
#include <string>
#include <concepts>

// Compound Requirement

// #1. noexcept
template<typename T>
concept HasNothrowFoo = requires(T c) {
	{ c.foo() } noexcept;		  
};

// #2. 반환 타입 조사
template<typename T>
concept HasFooReturnsInt = requires(T c) {
	{c.foo()} -> std::same_as<int>;
};

template<typename T>
concept HasFooReturnsConvertibleInt = requires(T c) {

	{c.foo()} -> std::convertible_to<int>;			  
};


template<typename T>
concept ReturnTypeCheckExample = requires(T c) {

	{ c.f1() } -> int;					// error
	{ c.f2() } -> std::is_integral_v;	// error

	{ c.f3() } -> std::integral;		// ok
			    //std::integral<decltype(c.f3())> 

	{ c.f4() } -> std::same_as<int>;
			   // std::same_as<decltype(c.f4()), int>	

	{ c.f5() } -> std::convertible_to<int>;			  
			  // std::convertible_to<decltype(c.f5()), int>;			  
};


int main() {


}





