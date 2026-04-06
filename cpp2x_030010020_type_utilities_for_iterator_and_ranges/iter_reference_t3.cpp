#include <vector>
#include <print>
#include "print_type.h"

template<typename I> void foo(I it)
{
	using T1 = std::iter_value_t<I>;		
	using T2 = std::iter_value_t<I>&;		
	using T3 = std::iter_reference_t<I>; // *it

	std::println("{}", get_type_name<T1>() ); // bool
	std::println("{}", get_type_name<T2>() ); // bool&
	std::println("{}", get_type_name<T3>() ); // 
}
int main()
{	
	std::vector<bool>  v{true, false, true};	

	bool b1 = v[0]; // 
	auto b2 = v[0];
	std::println("{}", typeid(b1).name()); // bool
	std::println("{}", typeid(b2).name()); // ?

	foo( v.begin() );		
}
