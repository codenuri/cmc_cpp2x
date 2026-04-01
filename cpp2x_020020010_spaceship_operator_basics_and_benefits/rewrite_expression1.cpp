#include <compare>
#include <print>

class Int32
{
    int value;
public:
    explicit Int32(int v) : value{v} {}

	bool operator==(const Int32& other) const 
	{
		return value == other.value;
	}
};
int main()
{ 
    Int32 a{10};
    Int32 b{20};

	std::println("{}", a == b ); 	// ok
	std::println("{}", a != b );	// ok    
//	std::println("{}", a < b );     // error
}