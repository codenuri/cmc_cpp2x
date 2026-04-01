#include <print>

class Int32
{
    int value;
public:
    explicit Int32(int v = 0) : value(v) {}

	// auto operator<=>(const Int32& other) const 
	// {
	// 	return value <=> other.value;
	// }	

	std::strong_ordering operator<=>(const Int32& other) const 
	{
		if ( value > other.value ) 
			return std::strong_ordering::greater;
		
		if ( value < other.value ) 
			return std::strong_ordering::less;

		return std::strong_ordering::equal;
	}

};

int main()
{ 
    Int32 n1{10};
    Int32 n2{20};
 
	auto ret = n1 <=> n2;  

	if ( ret > 0 ) {}
	if ( ret < 0 ) {}
	if ( ret == 0 ) {}
}


	