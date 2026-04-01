#include <concepts>
#include <vector>
#include <list>
#include <print>

template<typename T>
void check(T iter)
{
	// iterator category 를 나타내는 concept
	// C++20 이전 : iterator category 를 추상 적인 개념으로만 정의
	// C++20 이후 : iterator category 를 concept 문법을 사용해서 명확하게 정의
	std::println("{}", std::input_iterator<T> );
	std::println("{}", std::forward_iterator<T> );
	std::println("{}", std::bidirectional_iterator<T> );
	std::println("{}", std::random_access_iterator<T> );
	std::println("{}", std::contiguous_iterator<T> );
}
int main()
{	
	std::vector v{1,2,3};
	std::list   s{1,2,3};

	check(v.begin()); 	// contiguous_iterator
					 	// 모든 반복자 조건을 만족
						// T, T, T, T, T					
	check(s.begin());	// bidirectional_iterator
						// T, T, T, F, F
}


template<std::bidirectional_iterator I, 
		 std::sentinel_for<I> S > requires std::permutable<I>
constexpr I reverse( I first, S last ) { ... }