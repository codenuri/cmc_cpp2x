#include <print>

template<typename ... Ts>
void foo(Ts ... args)
{	
	// args : 1, 2, 3.3, 4.4, 5.5
	auto a1 = args...[0];
	auto a2 = args...[3];

	std::println("{}, {}", a1, a2); // 1, 4.4

	std::println("{}", typeid(a1).name()); // int
	std::println("{}", typeid(a2).name()); // double
}

int main()
{	
	foo(1, 2, 3.3, 4.4, 5.5);
}