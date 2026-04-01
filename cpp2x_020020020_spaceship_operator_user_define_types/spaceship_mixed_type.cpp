#include <string>
#include <print>

class Temperature
{
	double value{0.0};
public:
	explicit Temperature(double temp) : value{temp} {}

	auto operator<=>(const Temperature& other) const 
	{	
		return value <=> other.value;
	}	
	auto operator<=>(double temp) const 
	{	
		return value <=> temp;
	}
	bool operator==(const Temperature& other) const 
	{	
		return value == other.value;
	}
	
	bool operator==(double temp) const 
	{	
		return value == temp;
	}		
};
int main() 
{
	Temperature t1{5.6};
	Temperature t2{3.3};

	auto ret1 = t1  <=> t2;
	auto ret2 = t1  <=> 7.2;
	auto ret3 = 3.1 <=> t1; // reversed rewrite expression

	bool b1 = t1 == t2;
	bool b2 = t1 == 3;
	bool b3 = 3  == t1;
}

