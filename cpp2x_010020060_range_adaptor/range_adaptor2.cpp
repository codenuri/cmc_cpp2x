#include <print>
#include <ranges>
#include <vector>

int main() 
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	// view 클래스를 직접 사용
	std::ranges::take_view tv1{v, 5};	

	// RAO(Range Adaptor Object)
	auto tv2 = std::views::take(v, 5);	

	for ( auto e : tv2 )
	{
		std::print("{}, ", e);
	}
	std::println();

}

