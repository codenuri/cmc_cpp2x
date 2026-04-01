#include <string>
#include <print>

class Person 
{
	std::string name;
	int age;
public:
	Person( const std::string& name, int age)
		: name{name}, age{age} {}

	// <=> 와 == 가 다른 논리를 가진 좋지 않은 코드
	auto operator<=>(const Person& other) const 
	{
		return age <=> other.age;
	}
	bool operator==(const Person& other) const 
	{
		return age == other.age && name == other.name;
	}
};
int main() 
{
	Person p1{"alice", 20};
	Person p2{"john",  20};

	std::println("{}", p1 == p2); 	// false

	auto ret = p1 <=> p2;

	if ( ret > 0 )      std::println("p1 > p2");
	else if ( ret < 0 ) std::println("p1 < p2");
	else                std::println("p1 == p2");
}