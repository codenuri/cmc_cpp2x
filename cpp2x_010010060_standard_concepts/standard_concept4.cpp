#include <concepts>
#include <string>
#include <print>
#include <type_traits>

// semiregular : 기본 생성/복사/대입/이동이 되는 타입	
//				 기본적인 객체로 다룰수 있는 타입

// regular     : semiregular + equality comparable ( == )
// 				 primitive 타입의 값 처럼 다룰수 있는 타입

class A 
{
	// special member function : 컴파일러에 의해서 제공되는 멤버
	// default ctor, copy ctor, copy assigment, move ctor, move assignement
};
class B 
{
public:
	bool operator==(const B& other) const = default;
};

int main()
{	
	std::println("{}", std::semiregular<A>);	// true
	std::println("{}", std::regular<A>);		// false
	
	std::println("{}", std::semiregular<B>);	// true
	std::println("{}", std::regular<B>);		// true

	std::println("{}", std::semiregular<int>);	// 	true
	std::println("{}", std::regular<int>);		// 	true
}
