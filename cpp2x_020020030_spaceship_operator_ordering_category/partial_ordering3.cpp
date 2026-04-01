#include <string>
#include <print>

class Person 
{
	std::string name;
public:
	Person(const std::string& n = "" ) : name{n}{}

	auto operator<=>(const Person& other) const 
	{
		return name <=> other.name;
	}
};

int main()
{
	Person p1;
	Person p2{"alice"};

	auto ret = p1 <=> p2;
}


