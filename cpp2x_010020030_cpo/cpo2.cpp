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

	void swap(Point& p1, Point& p2) { 
		std::println("graphics::swap"); 
	}
}

int main() {
	graphics::Point p1, p2;

	// #1. qualified name
	mystd::swap(p1, p2); // mystd::swap()

	// #2. unqualified name
	using mystd::swap;
	swap(p1, p2);		// graphics::swap()
}

