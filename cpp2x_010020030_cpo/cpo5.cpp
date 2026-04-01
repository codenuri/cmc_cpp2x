#include <print>
#include <algorithm>

namespace graphics {
	class Point {};

	void swap(Point& p1, Point& p2) { 
		std::println("graphics::swap"); 
	}
}


int main() {

	graphics::Point p1, p2;
	{
		std::swap(p1, p2); 	// std::swap() 
		using std::swap;
		swap(p1, p2);		// graphics::swap()		
	}
	std::println("-----------------");		
	{
		std::ranges::swap(p1, p2);	
		using std::ranges::swap;
		swap(p1, p2);	// std::ranges::swap() => graphics::swap()
	}
}
