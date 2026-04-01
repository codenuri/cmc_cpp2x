#include <string>
#include <print>

class Person 
{
	std::string name;
public:
	Person(const std::string& n = "" ) : name{n}{}

	std::partial_ordering operator<=>(const Person& other) const 
	{
		if ( name == "" || other.name == "" ) 
			return std::partial_ordering::unordered;

		return name <=> other.name;
	}
};

int main()
{
	Person p1;
	Person p2{"alice"};

	auto ret = p1 <=> p2;

	if ( ret == std::partial_ordering::unordered )
	{
		std::println("unordered");
	}
}

