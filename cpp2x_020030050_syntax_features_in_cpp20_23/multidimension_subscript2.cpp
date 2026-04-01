#include <print>

struct MyType
{
	int data = 0;

	int& operator[]()
	{
		return data;
	}
};

int main()
{
	MyType mt;
	mt[] = 10;

	std::println("{}", mt.data);
}