#include <print>
#include <string>

template<typename T> 
concept container = requires(T c) {

	c.begin();
	c.end();
};

int main() {

	std::println("{}", container<std::string> ); // true
	std::println("{}", container<int[5]> );		 // false
}
