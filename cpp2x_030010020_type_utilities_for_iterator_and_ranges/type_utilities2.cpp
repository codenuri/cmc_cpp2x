#include <vector>
#include <ranges>

template<typename T> void foo(const T& range)
{
    // T 가 Container(Range) 일때 요소의 타입을 구하는 방법

	// C++98
	typename T::value_type n1;

	// C++20
	std::ranges::range_value_t<T> n2;
}

int main()
{	
	int x[5]{ 1, 2, 3, 4, 5 };
	std::vector v{ 1, 2, 3, 4, 5 };

	foo( v );
	foo( v | std::views::take(3) );
	foo( x );
}
