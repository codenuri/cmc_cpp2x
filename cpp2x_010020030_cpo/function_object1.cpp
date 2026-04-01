#include <print>

struct Plus {

	int operator()(int a, int b) const {
		return a + b;
	}
};

int main() {
	
	Plus p;

	int n1 = p(1, 2);
	
	int n2 = p.operator()(1, 2);

	std::println("{}, {}", n1, n2); // 3, 3
}