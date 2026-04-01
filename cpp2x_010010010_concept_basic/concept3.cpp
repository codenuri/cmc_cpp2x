#include <print>
#include <string>
#include <vector>

template<typename T>
concept container = requires(T& c) {

	c.begin();
	c.end();
};

template<typename T>
void foo(const T& a) {

	bool b = container<T>;
	
	std::println("{}", b );
}

int main() {

	int n = 0;
	std::string s = "abc";
	std::vector v = {1,2,3};

	foo(n);	// false
	foo(s);	// true
	foo(v);	// true
}
