#include <print>
#include <ranges>
#include <vector>

int main() 
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	auto v1 = std::views::take   ( v, 5);
	auto v2 = std::views::filter ( v, [](int n) { return n % 2 == 0;});
	auto v3 = std::views::reverse( v );

	// view 생성 vs RACO 생성
	auto tv1 = std::views::take(v, 5);	
	auto tvc = std::views::take(5);		

	// RACO 에 range 을 연결해서 view 를 만드는 2가지 방법
	auto tv2 = tvc(v);	
	auto tv3 = v | tvc;	

	// RACO 생성과 pipeline 을 한번에
	auto tv4 = v | std::views::take(5);
	auto tv5 = v | std::views::reverse;  // reverse(range) 에서 range 제거

	for ( auto e : tv5 ){
		std::print("{}, ", e);
	}
	std::println();
}
