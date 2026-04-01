#include <print>

class Int32
{
    int value;
public:
    explicit Int32(int v = 0) : value(v) {}
 
	auto operator<=>(const Int32& other) const 
	{
		return value <=> other.value;
	}	
};

int main()
{ 
    Int32 n1{10};
    Int32 n2{20};
 
	auto ret = n1 <=> n2;  

}


	