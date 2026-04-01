#include <print>

class Point {
public:
	int x;
	int y;

	void set1(int a, int b) // void set1(Point* this, ...)
	{
		x = a;
		y = b;
	}
	void set2(this Point& self, int a, int b) 
	{
		self.x = a;
		self.y = b;
	}	
};
int main() 
{
	Point pt;

	pt.set1(1, 1);
	pt.set2(2, 2);

	std::println("{}, {}", pt.x, pt.y);
}