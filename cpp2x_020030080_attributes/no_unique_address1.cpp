#include <print>

struct Empty 
{
    void foo() {}
};

struct Data
{
    [[no_unique_address]] Empty e;	// 1 => 0
    int   n;	// 4	
};

int main()
{
    std::println("{}", sizeof(Empty)); 	// 1
    std::println("{}", sizeof(Data));	// 8 => 4
}