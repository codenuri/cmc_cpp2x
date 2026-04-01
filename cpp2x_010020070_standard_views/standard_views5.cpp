#include <print>
#include <vector>
#include <list>
#include <ranges>

void p(std::ranges::view auto view)
{
	std::println("{}", view);	
}

int main() 
{
	std::vector<std::list<int>> vs{ {1,2}, {3,4,5}, {6,7,8} };

	p( vs | std::views::join );		// [1, 2, 3, 4, 5, 6, 7, 8]


    std::string_view s = "aa,bbb,cccc";
    
	p( s | std::views::split(',') );	// [['a', 'a'], ['b', 'b', 'b'], ['c', 'c', 'c', 'c']]	


    std::vector<int> v1{1,2,3};
    std::vector<int> v2{10,20,30,40};
	
	p( std::views::zip(v1, v2) );		// [(1, 10), (2, 20), (3, 30)]
	p( std::views::zip_transform([](int a, int b){ return a + b; }, v1, v2 ) );	// [11, 22, 33]
}