#include <vector>
#include <algorithm>
#include <print>
namespace rng = std::ranges;

struct Point {
	int x, y;
	int get_y() const { return y;}
};

int main() {

	std::vector<Point> v = { {1,1}, {2,2}, {3,3}, {4,4} };

	// # find_if : unary predicate 만 전달 가능
	auto ret1 = rng::find_if(v, 
						[](const Point& pt){ return pt.y == 3;});

	// # projection
	auto ret2 = rng::find(v, 3, &Point::y);	
	auto ret3 = rng::find(v, 3, &Point::get_y);	
	auto ret4 = rng::find(v, 3, [](const Point& p){ return p.y;});	
	auto ret5 = rng::find(v, 3, [](const Point& p) -> const int& { return p.y;});	

	// # find_if & projection
	auto ret6 = rng::find_if(v, [](int n){ return n % 3 == 0; }, &Point::y);

	// # iterator version
	auto ret7 = rng::find_if(v.begin(), v.end(), 
								[](int n){ return n % 3 == 0; }, &Point::y);
}