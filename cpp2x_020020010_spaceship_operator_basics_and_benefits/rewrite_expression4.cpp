#include <compare>

class Int32
{
    int value;
public:
    explicit Int32(int v) : value{v} {}

	auto operator<=>(const Int32& other) const = default;

	auto operator<=>(int other) const { return value <=> other; }
};

int main()
{ 
    Int32 n{10};

	// Int32 <=> int

	bool b1 = n < 1; // 1️⃣ (n <=> 1) < 0 --> n.operator<=>(1) < 0

	bool b2 = 1 < n; // 1️⃣ (1 <=> n) < 0 --> 1.operator<=>(n) < 0
					 // 2️⃣ 0 < (n <=> 1) --> 0 < n.operator<=>(1)
}
