#include <print>
#include <vector>
#include <mdspan>

int main()
{
	int x[6]{ 0,1,2,3,4,5 };

	// 정적 크기 mdspan
	std::mdspan<int, std::extents<std::size_t, 2, 3>> ms1{x};						
	std::mdspan<int, std::extents<std::size_t, 2, std::dynamic_extent>> ms2{x, 3}; 
	std::mdspan<int, std::extents<std::size_t, std::dynamic_extent, 3>> ms3{x, 2}; 
	std::mdspan ms4{x, 2, 3}; // 모두 동적 크기
	
	std::println("{}", sizeof(ms1));	// 8
	std::println("{}", sizeof(ms2));	// 16
	std::println("{}", sizeof(ms3));	// 16
	std::println("{}", sizeof(ms4));	// 24


	// 2, 3 의 동적 크기를 가진 mdspan 만들기
	std::mdspan<int, std::extents<std::size_t, std::dynamic_extent, std::dynamic_extent>> ms5{x, 2, 3};
	std::mdspan<int, std::dextents<std::size_t, 2>> ms6{x, 2, 3};
//	std::mdspan<int> ms7{x, 2, 3);	// error
	std::mdspan ms8{x, 2, 3};	
}
