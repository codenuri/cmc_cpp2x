#include <concepts>
#include <string>
#include <print>
#include <type_traits>

// 호출 가능여부를 조사하는 concept
// std::invocable<F, T1, T2, ...> : F(T1, T2, ...) 형태로 호출이 가능한가 ?
// std::predicate<F, T1, T2, ...> : F(T1, T2, ...) 형태로 호출이 가능한가 + 반환 타입이 bool 로 변환
//																		  가능한가 ?
void foo(int, double) {}
int  goo(int, double) { return 0;}

template<typename T>
void check(T&& f)
{

	std::println("{}", std::invocable<T, int, double>);
	std::println("{}", std::invocable<T, int, int>);

	std::println("{}", std::predicate<T, int, double>);	
}
int main()
{		
	check(foo);	// T, T, F
	check(goo);	// T, T, T
}
