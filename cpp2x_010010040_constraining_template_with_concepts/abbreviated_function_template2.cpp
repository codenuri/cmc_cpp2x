#include <concepts>

void f1(std::integral auto a) {
}

// 제약이 없는 template
void f2(auto a) {	
}

int main() {
	
	f1(10);		// ok
//	f1(3.3);	// error

	f2(10);		// ok
	f2(3.3);	// ok
}

auto add1(auto a, auto b) {
	return a + b;
}

template<typename T1, typename T2>
auto add2(T1 a, T2 b) {
	return a + b;
}