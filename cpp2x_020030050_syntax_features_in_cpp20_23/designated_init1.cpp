struct Point
{
    int x = 0;
    int y = 0;
};

int main() 
{
	Point p1 = {1, 2};
	Point p2{1, 2};   

	Point p3 = {.x = 1, .y = 2};
	Point p4{.x = 1, .y = 2};   

	Point p5{.x = 1};	// ok
	Point p6{.y = 1};	// ok

	Point p7{.y = 2, .x = 1};	// error   
	Point p8{1, .y = 2};		// error
}


