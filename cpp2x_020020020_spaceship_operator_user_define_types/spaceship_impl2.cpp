#include <string>
#include <print>

class Person 
{
	std::string name;
	int age;
public:
	Person( const std::string& name, int age)
		: name{name}, age{age} {}

	std::strong_ordering operator<=>(const Person& other) const 
	{
		if ( name > other.name ) return std::strong_ordering::greater;
		if ( name < other.name ) return std::strong_ordering::less;
							  // return std::strong_ordering::equal;
							  
		return age <=> other.age;
	}
};
int main() 
{
	Person p1{"alice", 20};
	Person p2{"john",  30};

	auto ret = p1 <=> p2;

	if ( ret > 0 )      std::println("p1 > p2");
	else if ( ret < 0 ) std::println("p1 < p2");
	else                std::println("p1 == p2");
}