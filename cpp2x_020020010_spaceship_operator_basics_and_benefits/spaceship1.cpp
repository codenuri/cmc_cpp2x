#include <print>

int main()
{
    int a = 10;
	int b = 20;

    bool ret1 = a < b;

	auto ret2 = a <=> b;

    if      ( ret2 > 0)  std::println("a > b");
    else if ( ret2 < 0)  std::println("a < b");
    else if ( ret2 ==0)  std::println("a == b");
}