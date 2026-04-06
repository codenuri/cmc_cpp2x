#include <print>
#include <span>

void f1(std::span<int> sp)
{
	sp[0]  = 10;	// ok
	auto a = sp[0]; // ok
}

void f2(std::span<const int> sp)
{
	sp[0]  = 10;    // error
	auto a = sp[0]; // ok
}

int main()
{
	int x[5]{1, 2, 3, 4, 5};
	
	f1(x);
	f2(x);
}
