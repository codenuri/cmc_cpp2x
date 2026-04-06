#include <print>
#include <span>
#include <mdspan>

int main()
{
	int x[6]{0, 1, 2, 3, 4, 5};

	std::span   sp{x};
	std::mdspan ms{x, 2, 3};
	std::mdspan m3{x, 1, 2, 3};

	std::println("{}", sp[4]);   		// 4
	std::println("{}", ms[1, 1]); 		// 4	
	std::println("{}", m3[0, 1, 1]);	// 4 
	
	std::println("row = {}", ms.extent(0));	// 2	
	std::println("col = {}", ms.extent(1));	// 3	
}
