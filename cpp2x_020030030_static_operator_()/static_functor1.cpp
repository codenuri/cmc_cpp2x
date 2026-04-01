#include <print>

struct Plus1 {
	int operator()(int a, int b) const {
		return a + b;
	}
};
struct Plus2 {
	static int operator()(int a, int b) {
		return a + b;
	}
};
int main(){
	Plus1 p1;
	Plus2 p2;

	int n1 = p1(1,2); // p1.operator()(1, 2) => operator()(&p1, 1, 2)
	int n2 = p2(1,2); // p2.operator()(1, 2) => operator()(1, 2)

	std::println("{}", n1);
	std::println("{}", n2);
}




 