#include <print>

class Rect 
{
	int x, y, width, height;
public:
	Rect(int x, int y, int w, int h) 
		: x{x}, y{y}, width{w}, height{h} {} 

	int get_area() const { return width * height; }

	// auto operator<=>(const Rect& other) const 
	// {
	// 	return get_area() <=> other.get_area();
	// 		      // 정수 <=> 정수 이므로 
	// 		      // std::strong_ordering 타입

	// }

	// std::weak_ordering operator<=>(const Rect& other) const 
	// {	
	// 	auto ret = get_area() <=> other.get_area();

	// 	if ( ret > 0 ) return std::weak_ordering::greater;
	// 	if ( ret < 0 ) return std::weak_ordering::less;

	// 	// std::strong_ordering 의 경우 equal 
	// 	// std::weak_ordering 의 경우는 equivalent
	// 	return std::weak_ordering::equivalent;
	// }
	
	std::weak_ordering operator<=>(const Rect& other) const 
	{
		return get_area() <=> other.get_area();
	}

};

int main() 
{	
	Rect r1{1, 3, 5, 5};
	Rect r2{7, 2, 5, 5};

	auto ret = r1 <=> r2;

	std::println("{}", typeid(ret).name());



}

