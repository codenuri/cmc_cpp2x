#include <print>
#include <string>
#include <concepts>
#include <ranges>

template<typename T> 
concept container = requires(T& c) {

//	{ std::begin(c) } -> std::input_or_output_iterator;
//	{ std::end(c) }   -> std::input_or_output_iterator;

	std::ranges::begin(c);
	std::ranges::end(c);
};

struct A {
	int begin() { return 0; }
	int end()   { return 0; }
};

void note() {

	std::string s = "hello";

	auto it1 = s.begin(); 		      // C++98	ok
	auto it2 = std::begin(s);		  // C++11	ok
	auto it3 = std::ranges::begin(s); // C++20	ok

	A a;
	auto it4 = a.begin(); 		      // C++98	ok
	auto it5 = std::begin(a);		  // C++11	ok
//	auto it6 = std::ranges::begin(a); // C++20	error
}




int main() {

	std::println("{}", container<int[5]> );	// true
	std::println("{}", container<A> );		// false
}


