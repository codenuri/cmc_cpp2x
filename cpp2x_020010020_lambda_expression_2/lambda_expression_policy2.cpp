#include <set>
#include <iostream>

int main() 
{
	// C++11/14/17 스타일
	auto cmp = [](int a, int b){ return abs(a) < abs(b);};
	std::set<int, decltype(cmp)> s1(cmp);

	// C++20 스타일
	std::set<int, 
	       decltype([](int a, int b){ return abs(a) < abs(b);})> s;

	s.insert(1);
	s.insert(-2);
	s.insert(3);
	s.insert(-4);

	for(auto e : s)
	{
		std::cout << e << ", ";
	}
	std::cout << '\n';
}
