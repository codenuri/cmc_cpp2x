#include <print>
#include <ranges>
#include <vector>

int main() 
{
	std::vector v{1, 2, 3, 4, 5};

	namespace rng = std::ranges;
	namespace viw = std::views;
	
	auto a = viw::adjacent<3>(v);	// RAO 사용
//	rng::adjacent_view<rng::ref_view<std::vector<int>>, 3> a{v}; // View 클래스를 직접 사용

	for ( auto e : a ) 
	{
		std::println("{}", e);	// (1, 2, 3)
								// (2, 3, 4)
								// (3, 4, 5)
	}
	std::println();
}

