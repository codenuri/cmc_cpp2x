#include <string>
#include <print>

class Person 
{
	std::string name;
	int age;
public:
	Person( const std::string& name, int age)
		: name{name}, age{age} {}

	auto operator<=>(const Person& other) const = default;
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
