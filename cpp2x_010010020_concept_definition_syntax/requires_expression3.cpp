#include <print>
#include <type_traits>
#include <string>

template<typename T>
concept HasValueType = requires {
    typename T::value_type;
};

template<typename T>
concept HasIterator = requires {
    typename T::iterator;
};

int main() {

	std::println("{}", HasIterator<int>);		  // false
	std::println("{}", HasIterator<std::string>); // true
}

