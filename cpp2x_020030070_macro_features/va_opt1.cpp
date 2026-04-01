#include <cstdio>

//#define LOG(fmt, ...) printf(fmt, __VA_ARGS__)

#define LOG(fmt, ...) printf(fmt, ##__VA_ARGS__)


int main()
{
	int a = 3;
	int b = 4;

	LOG("a = %d, b = %d\n", a, b);

	LOG("hello\n");
}

