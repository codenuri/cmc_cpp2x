#include <print>

struct Point3D 
{
	int x = 1, y = 2, z = 3;


	int* begin() { return &x; }
	int* end()   { return &z + 1; }	
};

int main()
{
	Point3D p;

	for( auto e : p ) 
	{
		std::print("{}, ", e );
	}
	
	std::println();
}