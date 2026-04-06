#include <vector>
#include <print>

template<typename I> 
void foo(I first, I last)
{
	// 2개 반복자의 거리를 구하고 싶다
//	int n = last - first;
//	std::iter_difference_t<I> n = last - first;
//	auto n = last - first;
	auto n = std::distance(first, last);
	
	std::println("{}", n);
}

int main()
{	
	std::vector<int> v{1, 2, 3, 4, 5};	
	foo( v.begin(), v.end() );	
}
