#include <print>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {

    std::vector src = { 1, 2, 3, 4, 5};
    std::vector dst = { 9, 8, 7, 6, 5};

	auto it = std::ranges::find(src, 3);

	auto out = std::copy(src.begin(), it, 
						 dst.begin());

    std::println("{}", *out);

    auto result = std::ranges::copy(src.begin(), it,
									dst.begin());
	std::println("{}", *result.in);
	std::println("{}", *result.out);

}

