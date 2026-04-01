#include <functional>

class Sample 
{
	int data = 0;
public:
	auto foo()
	{
		int a = 10;
		return [=] { return a + data;};
	}
};
int main()
{
	std::function<int()> f;
	{
		Sample s;
		f = s.foo();
	} // <= s 파괴
	auto ret = f(); // 버그	
}