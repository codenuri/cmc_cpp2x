#include <vector>
#include <algorithm>
#include <print>
namespace rng = std::ranges;

struct Point {
	int x, y;
};

int main() {
	
	std::vector<Point> v = {{1,1}, {2,2}, {3,3}, {4,4}};
	
	auto ret1 = rng::find_if(v, 
				 [](const Point& pt){ return pt.y == 3;});

	auto ret2 = rng::find(v, 3, &Point::y);	

	std::println("{}, {}", ret1->x, ret1->y);
	std::println("{}, {}", ret2->x, ret2->y);
}