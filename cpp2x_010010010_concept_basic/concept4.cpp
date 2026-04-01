#include <print>
#include <string>

template<typename T>
concept container = requires(T& c) {
	c.begin();
	c.end();
};

template<typename T>
void f1(const T& a) { }

template<typename T> requires container<T>
void f2(const T& a) { }

int main() {
	int n = 0;
	std::string s = "abc";

	f1(n);	// ok
	f1(s);	// ok

//	f2(n);	// error
	f2(s); 	// ok
}
