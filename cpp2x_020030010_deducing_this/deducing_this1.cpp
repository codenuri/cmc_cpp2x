class Point {
public:
	int x;
	int y;

	void set(int a, int b) {
		x = a;
		y = b;
	}
};

int main() {

	Point p1, p2;

	p1.set(1, 1);
	p2.set(2, 2);
}
