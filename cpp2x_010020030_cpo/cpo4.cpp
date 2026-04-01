#include <print>

namespace mystd {

	template<typename T>
	concept can_adl_swap = requires(T& a, T& b) {
		swap(a, b); 
	};

	struct cpo {		
		template<typename T>
		void operator()(T& a, T& b) {
			if constexpr ( can_adl_swap<T> )
			
				swap(a, b);
			else 
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
