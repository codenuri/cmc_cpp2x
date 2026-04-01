#include <compare>

class Int32
{
    int value;
public:
    explicit Int32(int v) : value{v} {}

	auto operator<=>(const Int32& other) const 
	{
		return value <=> other.value;
	}
};

int main()
{ 
    Int32 a{10};
    Int32 b{20};

	auto ret = a <=> b;

	bool b1 = a < b;  	// ok (a <=> b) < 0
	bool b2 = a > b;  	// ok (a <=> b) > 0
	bool b3 = a <= b;  	// ok (a <=> b) <= 0
	bool b4 = a >= b;	// ok (a <=> b) >= 0    	
//  bool b5 = a == b;  	// error
//  bool b6 = a != b;  	// error
}