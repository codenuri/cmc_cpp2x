#include <print>
#include <vector>
#include <map>
#include <ranges>

void p(std::ranges::view auto view)
{
	std::println("{}", view);	
}

int main() 
{
    std::vector<std::tuple<int, char, const char*>> v{
        {1, 'A', "one"},
        {2, 'B', "two"},
        {3, 'C', "three"}
    };

	// v 의 요소 자체가 tuple(또는 pair) 형태 일때
	// 각 요소의 2번째 만 볼수 있는 view
    p( v | std::views::elements<2> ); // ["one", "two", "three"]	

    std::map<int, char> m{{1,'A'}, {2,'B'}, {3,'C'}};

	p( m | std::views::keys );		// [1, 2, 3]
	p( m | std::views::values );	// ['A', 'B', 'C']

	p( m | std::views::elements<0> );// [1, 2, 3]	
	p( m | std::views::elements<1> );// ['A', 'B', 'C']

}