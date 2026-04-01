template<typename Key, typename Compare>
class MySet 
{
	Compare cmp;	// A
public:
	MySet() {}
	MySet(Compare c) : cmp{c} {} // B
};

int main() 
{
	// C++20 이전 
	MySet<int, decltype([](int a, int b){ return abs(a) < abs(b);}) > s1;
			// 🚨 error.
			// 평가되지 않은 표현식에 람다표현식 사용할수 없음

	auto cmp = [](int a, int b){ return abs(a) < abs(b);};

	MySet<int, decltype(cmp) > s1;
			// 🚨 error
			// 1. decltype(cmp)	는 에러 아님
			// 2. 하지만 MySet 의 A 코드가 되려면 디폴트 생성자 필요


	MySet<int, decltype(cmp) > s1(cmp);	
			// ✅ ok
			// MySet 의 B 코드의 생성자 를 사용하므로 람다 표현식이 복사 생성자를 사용한것


	// C++20 이라면
	MySet<int, decltype([](int a, int b){ return abs(a) < abs(b);}) > s1;
			// ✅ ok
			// 1. 람다표현식 자체를 평가되지 않은 표현식에 넣을수 있고
			// 2. 캡쳐 하지 않은 람다표현식은 디폴트 생성자를 제공하므로 A 가 문제 없다

}
