#include <print>
#include <string>
#include <concepts>

template<typename T> 
concept container = requires(T& c) {

	{ std::begin(c) } -> std::input_or_output_iterator;
	{ std::end(c) }   -> std::input_or_output_iterator;
};

struct A {
	int begin() { return 0; }
	int end()   { return 0; }
};

int main() {

	std::println("{}", container<int[5]> );	// true
	std::println("{}", container<A> );		// false
}

void note() {

	// std::input_or_output_iterator<T>
	// => 입력 또는 출력 반복자 인지 조사하는 C++20 표준 concept

	std::println("{}", std::input_or_output_iterator<int> );					// false
	std::println("{}", std::input_or_output_iterator<std::string::iterator> );	// true
}