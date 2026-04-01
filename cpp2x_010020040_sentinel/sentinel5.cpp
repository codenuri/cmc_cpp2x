#include <print>
#include <concepts>
#include <string>

template<typename T>
concept container = requires(T& c) 
{
	// std::ranges::begin(c);
	// std::ranges::end(c);

	{ std::begin(c) } -> std::input_or_output_iterator;
	{ std::end(c) } -> std::input_or_output_iterator;
};

int main() {

	bool b = container<std::string>;
}
