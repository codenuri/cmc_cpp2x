#include <compare>

class Int32
{
    int value;
public:
    explicit Int32(int v) : value{v} {}

	auto operator<=>(const Int32& other) const = default;
};

int main()
{ 
    Int32 a{10};
    Int32 b{20};

	auto ret = a <=> b;

    bool b1 = a < b;  
    bool b2 = a > b;  
    bool b3 = a == b;  
    bool b4 = a != b;  
    bool b5 = a <= b;  
	bool b6 = a >= b;      
}