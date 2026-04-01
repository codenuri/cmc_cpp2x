#include <compare>

class Int32
{
    int value;
public:
    explicit Int32(int v = 0) : value(v) {}

	auto operator<=>(const Int32& other) const = default;
};

int main()
{ 
    Int32 n1{10};
    Int32 n2{20};

    bool b1 = n1 < n2;  
    bool b2 = n1 > n2;  
    bool b3 = n1 == n2;  
    bool b4 = n1 != n2;  
    bool b5 = n1 <= n2;  
	bool b6 = n1 >= n2;      
	auto ret = n1 <=> n2;  
}