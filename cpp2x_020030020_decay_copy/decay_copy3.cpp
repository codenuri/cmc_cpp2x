#include <vector>
#include <print>
#include <algorithm>

int main() 
{
	std::vector v{1, 2, 3, 1, 2, 3, 1, 2, 3, 1};

//	auto ret = std::ranges::remove(v, v.front());

	// #1. 복사본 변수 사용
	// auto value = v.front();
	// auto ret = std::ranges::remove(v, value);

	// #2. static_cast 로 prvalue 만들기
//	auto ret = std::ranges::remove(v, static_cast<int>(v.front()));


	// #3. auto{} 로 prvalue 만들기
	auto ret = std::ranges::remove(v, auto{v.front()});


	v.erase(ret.begin(), ret.end());

	for( auto e : v )
	{
		std::print("{}, ", e);
	}
	std::println();
}

