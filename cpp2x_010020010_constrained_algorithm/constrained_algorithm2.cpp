#include <print>
#include <forward_list>
#include <algorithm>

int main() {

	std::forward_list s = {1, 3, 2, 5, 4};

	// 아래 2개 코드의 에러 메세지 비교
	// => 파일 이름과 줄 번호도 비교

//	std::reverse(s.begin(), s.end());

	std::ranges::reverse(s.begin(), s.end());
}
