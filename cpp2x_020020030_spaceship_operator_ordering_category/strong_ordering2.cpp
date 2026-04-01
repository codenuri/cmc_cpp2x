#include <print>

int main() 
{
	int a = 3;
	int b = 3;

	auto ret = a <=> b;

	std::println("{}", typeid(ret).name());
}

