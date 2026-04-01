#include <print>
#include <concepts>

template<std::integral T> 
void foo(T a) {
	
	auto ret = a % 3;
}

int main() {

	foo(3.4);	// error 메세지 확인
}
