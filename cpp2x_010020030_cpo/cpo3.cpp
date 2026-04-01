#include <print>

namespace mystd {

	struct cpo {		
		template<typename T>
		void operator()(T& a, T& b) {
			std::println("mystd::swap");
		}
	};

	cpo swap;
}

namespace graphics {
	class Point {};

	void swap(Point& p1, Point& p2) { 
		std::println("graphics::swap"); 
	}
}

int main() {
	graphics::Point p1, p2;

	// 방법 #1. qualified name
	mystd::swap(p1, p2);

	// 방법 #2. unqualified name
	using mystd::swap;
	swap(p1, p2);
}
