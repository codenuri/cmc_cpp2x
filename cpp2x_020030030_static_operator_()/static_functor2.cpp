int add(int a, int b) { return a + b;}

struct Plus {
	static int operator()(int a, int b) {
		return a + b;
	}
	using FP = int(*)(int, int);

	operator FP() { return &Plus::operator();}
};

void foo( int(*f)(int, int) ) { }

int main() {

	Plus p;

	foo(add);
	foo(p);
}
