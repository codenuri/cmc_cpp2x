#include <vector>
#include <print>
#include "print_type.h" // get_type_name<T>()
						// => T 타입의 이름을 문자열로 반환

template<typename I> void foo(I it)
{
	using T1 = std::iter_value_t<I>;	 // int	
	using T2 = std::iter_value_t<I>&;	 // int&
	using T3 = std::iter_reference_t<I>; // *it => int&

	std::println("{}", get_type_name<T1>() );
	std::println("{}", get_type_name<T2>() );
	std::println("{}", get_type_name<T3>() );
}
int main()
{	
	std::vector<int>  v{1, 2, 3, 4, 5};	
	foo( v.begin() );	
}
