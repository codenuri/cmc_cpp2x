#include <print>
#include <string>

template<typename T> 
concept container = requires(T& c) {

	std::begin(c);
	std::end(c);
};

int main() {

	std::println("{}", container<std::string> ); // true
	std::println("{}", container<int[5]> );		 // true
}

void note() {

	std::string s = "hello";
	int x[5]      = {1,2,3,4,5};
	

	// 멤버 함수 begin() - C++98
	auto a1 = s.begin();	// ok
//	auto a2 = x.begin();	// error

	// 일반 함수 std::begin() - C++11
	auto a3 = std::begin(s);	// ok
	auto a4 = std::begin(x); 	// ok
}

