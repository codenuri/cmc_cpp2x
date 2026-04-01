#include <print>
#include <ranges>
#include <vector>

int main() 
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	namespace rng = std::ranges;
	namespace viw = std::views;
	
//	for ( auto e : rng::reverse_view{rng::take_view{v, 5}} ) // view 클래스의 임시객체 사용
	for ( auto e : viw::reverse(viw::take(v, 5)) ) 			 // RAO 사용
	{
		std::print("{}, ", e);
	}
	std::println();

}

