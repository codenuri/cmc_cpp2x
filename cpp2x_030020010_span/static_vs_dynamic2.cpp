#include <print>
#include <vector>
#include <span>

void f1(std::span<int>    ds) { }
void f2(std::span<int, 5> ss) { }

int main()
{
	int x1[5]{1,2,3,4,5};
	int x2[3]{1,2,3};

	f1(x1);	// ok
	f1(x2);	// ok

	f2(x1);	// ok
//	f2(x2);	// error
}

