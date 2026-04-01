#include <print>

void foo(const int& arg)
{
	std::println("{}", static_cast<const void*>(&arg));
}

int main()
{
	int n = 10;
	
	std::println("{}", static_cast<const void*>(&n));

	foo(n);
	
	foo( auto{n} );
	foo( auto(n) );

	foo( static_cast<int>(n) );
}
