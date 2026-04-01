#include <tuple>
#include <print>

int main() 
{
	std::tuple t{1, 3.2, 'A'};

	auto [a, b, c] = t;

	

	std::println("{}, {}", a, c);
}

