#include <print>
#include <type_traits>
#include <string>

template<typename T>
concept C1 = sizeof(T) > 4;	


template<typename T>
concept C2 = requires( T c ) {

	sizeof(T) > 4; 	// 이 표현식이 참인가 ? 가 아닌 
					// 이 표현식이 가능한가를 조사
};

template<typename T>
concept C3 = requires( T c ) {

	requires sizeof(T) > 4; 
};


template<typename T>
concept C4 = sizeof(T) > 4 && 
			 requires( T c ) {
	c.foo();
};

// Nested Requirement
template<typename T>
concept C5 = requires( T c ) {

	requires sizeof(T) > 4; 
	c.foo();	
};

int main() {

	std::println("{}", C1<int>); // false
	std::println("{}", C2<int>); // true
	std::println("{}", C3<int>); // false
}
