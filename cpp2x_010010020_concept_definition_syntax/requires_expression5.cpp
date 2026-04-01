#include <print>
#include <type_traits>
#include <concepts>
#include <vector>

template<typename T>
concept C = requires(T c) {

	c[0];		// simple requirement
	
	{ c.size() } noexcept -> std::same_as<std::size_t>;
				// compound requirement

	typename T::iterator;
				// type requirement

	requires std::is_default_constructible_v<T>;
				// nested requirement
};


int main() {

	std::println("{}", C<int>); 			// false
	std::println("{}", C<std::vector<int>>);// true
}
