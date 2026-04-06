#include <vector>
#include <ranges>

template<typename T> void foo(T first)
{
	// T 가 반복자 일때
	// T 가 가리키는 요소의 타입을 구하는 방법

	// C++98
	typename T::value_type n1;	
	typename std::iterator_traits<T>::value_type n2;

	// C++20
	std::iter_value_t<T> n3;
}

int main()
{	
	int x[5]{ 1, 2, 3, 4, 5 };
	std::vector v{ 1, 2, 3, 4, 5 };

	foo( v.begin() );	
	foo( std::begin(x) );
}
