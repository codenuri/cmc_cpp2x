#include "task.h"
#include <string>

struct ReadFile
{
	// 실제 코루틴의 기술적인 제어를 담당하는 Awaiter
	struct ReadFileAwaiter 
	{
		bool await_ready() const noexcept
		{
			return false;
		}
		void await_suspend(std::coroutine_handle<> h) const
		{			
		}
		void await_resume() const noexcept {}
	};

	// 비동기 파일 읽기 작업을 위한 멤버들
	std::string filename;

	// co_await 제공
	ReadFileAwaiter operator co_await() 
	{
		return {};
	}
};

Task foo()
{
    std::println("foo #1");
	
	// 다음중 가독성이 좋은 코드는 ?
//	co_await ReadFileAwaiter{};
	co_await ReadFile{"sample.txt"};

	std::println("foo #2");	
}

int main()
{
    Task task = foo();

	task.resume();
	std::println("main");
	task.resume();
}
