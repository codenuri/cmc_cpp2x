#include <string>
#include <print>

int main() 
{
	std::string s1 = "to be or non to be";
	std::string s2 = "to be or non to be";

	// s1, s2 의 크기 관계를 조사하고 싶다

	// #1. 기존 비교 연산자는 2번의 비교 필요
    if        ( s1 < s2 ) {
	} else if ( s1 > s2 ) {
	} else {	// s1 == s2
	}

	// #2. <=> 연산자는 한번에 비교 가능
	auto ret = s1 <=> s2;

	// 비교는 완료. 아래 코드는 결과를 해석하는 과정
   	if      ( ret > 0)  std::println("a > b");
    else if ( ret < 0)  std::println("a < b");
    else if ( ret ==0)  std::println("a == b");	
}
