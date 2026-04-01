#include <print>

template<typename T, typename U> struct PAIR
{
	T first;
	U second;	

	PAIR(T a, U b) : first{a}, second{b} {}
};

int main()
{
    // 메모리 주소와 삭제자를 보관.
    PAIR p( malloc(100), 				// 8	
			[](void* p){free(p); } ); 	// 1

    std::println("{}", sizeof(p)); // 
}