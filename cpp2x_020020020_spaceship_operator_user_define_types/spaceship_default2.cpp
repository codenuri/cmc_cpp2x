#include <compare>

struct A 
{
	auto operator<=>(const A& t) const = default;
};

class MyType 
{
	A a;
	int data = 0;
public:
	auto operator<=>(const MyType& t) const = default;
};
int main()
{
	MyType m1;
	MyType m2;

	auto ret = m1 <=> m2;
}