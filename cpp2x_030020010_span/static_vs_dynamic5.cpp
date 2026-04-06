#include <print>
#include <vector>
#include <span>

int main()
{
	int x[5]{1, 2, 3, 4, 5};
	
	std::span<int> sp{x};

	auto sp1 = sp.first(3);		// sp1 : std::span<int>
	auto sp2 = sp.first<3>();	// sp2 : std::span<int, 3>

	std::println("{}", typeid(sp1).name());
	std::println("{}", typeid(sp2).name());
}
