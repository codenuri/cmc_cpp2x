class Point {
public:

	void f1()       {}
	void f1() const {}

	void f2(this Point& self) {}
	void f2(this const Point& self) {}
};

int main() 
{
	Point pt;
	const Point cp;

	pt.f1();
	cp.f1();
	pt.f2();
	cp.f2();	
}
