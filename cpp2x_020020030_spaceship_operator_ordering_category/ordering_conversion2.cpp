#include <print>

class Data 
{
	int    n = 0;
	double d = 0;
public:

	std::partial_ordering  operator<=>(const Data& other) const 		
	{
		if ( auto ret = n <=> other.n; ret != 0 )
			return ret;

		return d <=> other.d;
	}

//	auto operator<=>(const Data& other) const = default; // ok 
};




int main()
{
	Data d1, d2;

	auto ret = d1 <=> d2;

	std::println("{}", typeid(ret).name());
}

