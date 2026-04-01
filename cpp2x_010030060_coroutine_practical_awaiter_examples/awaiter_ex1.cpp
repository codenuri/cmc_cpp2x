#include "task.h"
#include <thread>
#include <chrono>
using namespace std::literals;

struct NewThreadAwaiter 
{
	bool await_ready() const noexcept { return false; }

    void await_suspend(std::coroutine_handle<> h) 
	{
		// 새로운 스레드가 나머지 부분을 실행( h.resume() )
        std::thread t( [h]() { h.resume(); } );
		
		t.detach();
    }
    void await_resume() {}
};

Task foo()
{
	std::println("foo #1 : {}", std::this_thread::get_id());

	co_await NewThreadAwaiter{};

	std::println("foo #2 : {}", std::this_thread::get_id());
}

int main()
{
	Task task = foo();

	task.resume();
	std::println("continue main: {}", std::this_thread::get_id());
	std::this_thread::sleep_for(1s);
	std::println("finish main");
}

#include <stdio.h>

int main()
{
	printf("Hello, World");
}