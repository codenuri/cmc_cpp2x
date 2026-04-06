#include <vector>
#include <span>

void f1(std::vector<int>& v)    { }
void f2(int* p, std::size_t sz) { }
void f3(std::span<int> sp)      { }

int main()
{
	int      x[5]{1, 2, 3, 4, 5};
	std::vector v{1, 2, 3, 4, 5};

//	f1(x); // error
	f1(v); // ok

	f2(x, 5);				// ok
	f2(v.data(), v.size());	// ok

	f3(x);	// ok
	f3(v);	// ok
}