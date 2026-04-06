
#include <vector>
#include <print>
#include "print_type.h" // for get_type_name<T>()

template<typename I> void foo(I it)
{
	using T1 = std::iter_value_t<I>;		
	using T2 = std::iter_value_t<I>&;		
	using T3 = std::iter_reference_t<I>; // *it

	std::println("{}", get_type_name<T1>() ); // int
	std::println("{}", get_type_name<T2>() ); // int&
	std::println("{}", get_type_name<T3>() ); // const int&
}

int main()
{	
	std::vector<int>  v{1, 2, 3, 4, 5};	
	foo( v.cbegin() );	// const iterator
}
