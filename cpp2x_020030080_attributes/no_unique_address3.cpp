#include <print>

template<typename T, typename U> struct PAIR
{
	[[no_unique_address]] T first;
	[[no_unique_address]] U second;	

	PAIR(T a, U b) : first{a}, second{b} {}
};

int main()
{
    PAIR p( malloc(100), 				// 	
			[](void* p){free(p); } ); 	// 

    std::println("{}", sizeof(p)); // 
}