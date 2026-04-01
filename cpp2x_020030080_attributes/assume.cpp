#include <cassert>

int f(int x)
{
	assert(x > 0);
    [[assume(x > 0)]];
    return 100 / x;
}

int main() 
{
	f(3);
}