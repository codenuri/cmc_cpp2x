#include <set>
#include <iostream>

struct AbsLess 
{
	bool operator()(int a, int b) const 
	{
		return abs(a) < abs(b);
	}
};


int main() 
{
//	std::set<int> s;
	std::set<int, AbsLess> s;
	
	s.insert(1);
	s.insert(-2);
	s.insert(3);
	s.insert(-4);

	for(auto e : s)
	{
		std::cout << e << ", ";	// -4, -2, 1, 3
								// 1, -2, 3, -4	
								
	}
	std::cout << '\n';
}
