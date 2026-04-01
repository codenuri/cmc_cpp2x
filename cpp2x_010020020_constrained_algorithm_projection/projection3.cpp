#include <print>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
namespace rgs = std::ranges;

int main() {	

	std::vector<std::string> v{"AAAA", "D", "BB", "CCC"};

	rgs::sort(v); // 오름차순 정렬 ["AAAA", "BB", "CCC", "D"]
	
	rgs::sort(v, [](const std::string& a, const std::string& b) { return a > b; });	// 내림 차순

	
	rgs::sort(v, std::greater{} );	// a > b 비교, 내림 차순
	rgs::sort(v, std::less{} );		// a < b 비교. 오름 차순, rgs::sort(v) 와 동일
	rgs::sort(v, {} );				// 디폴트 값인 std::less{} 사용하라는 의미(위와 동일)



	// 사전순이 아닌 문자열이 길이로 비교
	// #1. 2번째 인자로 이항 비교 함수 전달
	rgs::sort(v, [](const std::string& s1, const std::string& s2) { return s1.size() < s2.size();});

	// #2. 3번째 인자로 Projection 사용
	rgs::sort(v, {}, &std::string::size);


	// 문자열의 길이로 내림차순 정렬
	rgs::sort(v, std::greater{}, &std::string::size);

	for( auto& e : v)
		std::print("{}, ", e);	// "AAAA", "CCC", "BB", "A"
								// 4       3      2     1
	std::println();
}