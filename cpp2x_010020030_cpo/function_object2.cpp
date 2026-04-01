#include <print>
#include <vector>
#include <algorithm>

int main() {
	
	int n1 = std::ranges::max(1, 2);
	int n2 = std::ranges::max.operator()(1, 2);

	std::println("{}, {}", n1, n2); // 2, 2
	
	std::vector v = {1, 3, 5, 2, 4, 6};

	std::ranges::sort(v);
	std::ranges::sort.operator()(v);

	auto it1 = std::ranges::begin(v);
	auto it2 = std::ranges::begin.operator()(v);
}