#include <generator>
#include <print>

std::generator<int> foo()
{
	std::println("	foo #1");
	co_yield 1;	// Suspend
				// 실행 흐름을 멈추고 호출자로 이동(1전달)


	std::println("	foo #2");
	co_yield 2;	
}

int main()
{
	for( auto n : foo() )	// Call, Resume
	{						
		std::println("main : {}", n);
	}
}