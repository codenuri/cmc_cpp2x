#include <print>
#include <vector>
#include <algorithm>

int main()
{
	//-------------------------------------------------------
    // C++98 : "erase - remove idioms"
	std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };	

	auto iter = std::remove_if(v1.begin(), v1.end(), [](int n) { return n % 2 == 0; });

	v1.erase(iter, v1.end());

	//-------------------------------------------------------
	// C++20 : std::erase / std::erase_if
    std::vector<int> v2 = { 1,2,3,4,5,6,7,8,9,10 };
    
    std::erase(v2, 3);
	std::erase_if(v2, [](int n) { return n % 2 == 0; });

	std::println("{}", v2);
	std::println("{}, {}", v2.size(), v2.capacity() );
	//------------------------------------------------------

    // std::erase(v2, 3); 					 // ok
	// std::erase(v2.begin(), v2.end(), 3); // error	
}