#include <print>
#include <concepts>

class Rect 
{
	int x, y, width, height;
public:
	Rect(int x, int y, int w, int h) : x{x}, y{y}, width{w}, height{h} {} 

	int get_area() const { return width * height; }

	// 아래 코드는 반환 타입을 잘못 사용한 경우
	std::strong_ordering operator<=>(const Rect& other) const 
	{
		return get_area() <=> other.get_area();
	}
	bool operator==(const Rect& other) const 
	{
		return 	x == other.x && y == other.y 
				&& width == other.width 
				&& height == other.height;
	}
};

template<typename T> 
		requires std::three_way_comparable<T, std::strong_ordering>
void foo(T& a, T& b)
{
	if ( (a <=> b) == 0)
	{
		// a 와 b 는 동일한 값을 가진 객체 라고 생각하고 코드 작성
	}
}

int main() 
{	
	Rect r1{1, 3, 5, 5};
	Rect r2{7, 2, 5, 5};

	foo(r1, r2);
}

