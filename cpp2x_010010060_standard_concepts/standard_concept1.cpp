#include <concepts>
#include <print>

// template<typename T>
template<std::integral T>
T factorial(T n)
{
    T r = 1;
    for (T i = 1; i <= n; ++i)
        r *= i;
    return r;
}

int main()
{
	std::println("{}", factorial(5));
}