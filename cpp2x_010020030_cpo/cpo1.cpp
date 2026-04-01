#include <print>

namespace mystd 
{
	template<typename T>
	void swap(T& a, T& b) {
		std::println("mystd::swap");
	}
}

namespace graphics 
{
	class Point {};
}

int main() {
	
	graphics::Point p1, p2;

	// 방법 #1. qualified name
	mystd::swap(p1, p2);
	
	// 방법 #2. using declaration
	using mystd::swap;
	swap(p1, p2);

	// 방법 #3. using directive
	using namespace mystd;
	swap(p1, p2);
}
