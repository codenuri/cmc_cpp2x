#include <print>
#include <vector>	

template<typename T> 
void foo(const T& arg) {

	// T 가 STL 컨테이너 인지 조사하고 싶다 ?
}

int main() {

	int n = 0;
	std::vector v = {1, 2, 3};

	foo(n);	// false
	foo(v);	// true
}
