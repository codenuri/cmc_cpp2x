#include <vector>
#include <print>
#include <algorithm>

template<typename C>
void foo(C& v)
{
	// static_cast 를 사용한 prvalue 만들기 : 타입을 알아야 한다
//	auto ret = std::ranges::remove(v, static_cast<?>(v.front()));

//	auto ret = std::ranges::remove(v, static_cast<typename C::value_type>(v.front()));
//	auto ret = std::ranges::remove(v, static_cast<std::decay_t<decltype(v.front())>>(v.front()));


	// auto {exp} : 타입을 알필요 없다. 컴파일러의 타입 추론에 의해서 prvalue 생성
	auto ret = std::ranges::remove(v, auto{v.front()} );

	v.erase(ret.begin(), ret.end());
}

int main() 
{
	std::vector v{1, 2, 3, 1, 2, 3, 1, 2, 3, 1};

	foo(v);

	for( auto e : v ) {
		std::print("{}, ", e);
	}
	std::println();
}

