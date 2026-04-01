#include <print>
#include <vector>
#include <algorithm>

int main() {

	std::vector v = {1, 3, 2, 5, 4};

	// C++98 algorithms
	std::sort(v.begin(), v.end());			

	// C++20 algorithms
	std::ranges::sort(v.begin(), v.end());  
	std::ranges::sort(v);  	
}
