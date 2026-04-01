#include <print>
#include <vector>
#include <algorithm>
#include <concepts>

template<typename I> void algo(I iterator)  {}
template<typename C> void algo(C container) {} // error


int main() {

	std::vector v = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

	std::sort(v.begin(), v.end()); // ok

	std::sort(v); // error
}
