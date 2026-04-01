#include <functional>

class Sample 
{
	int data = 0;
public:
	void foo()
	{
		int a = 10;
		
		auto f = [=] { return a + data;}; 
					// 		this->data
					// C++11/14/17 : compile-ok
					// C++20 ~     : compile-error		

	}
};
int main()
{

}