#include <print>
#include <type_traits>
#include <string>
#include <concepts>

// Simple Requirement
template<typename T>
concept Addable = requires(T a, T b) {
    a + b;	
};

template<typename T>
concept HasFoo = requires(T c) {
	c.foo();
};

template<typename T>
concept Subscriptable = requires(T c) {
	c[0];
};

template<typename T>
concept Dereferenceable = requires(T c) {
	*c;
};

// 3개의 Simple Requirement 
// 를 가지고 있는 concept
template<typename T>
concept MyConcept = requires(T c) {
	c.foo();
	c.goo();
	c[0];
};

int main() {

}