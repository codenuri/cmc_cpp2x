#include <print>
#include <coroutine>

class Task 
{
public:
   	class promise_type 
	{
	public:
        Task get_return_object() { return Task{std::coroutine_handle<promise_type>::from_promise(*this)}; }
        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend()   noexcept { return {}; }
		void return_void() {}
        void unhandled_exception() { }
    };
    Task(const std::coroutine_handle<promise_type> coro) : coro{coro} {}
	std::coroutine_handle<promise_type> coro;
};

Task foo()
{	
	co_await std::suspend_always{}; 	
}

void handle_pitfall_01_missing_destroy()
{
    Task t = foo();

    t.coro.resume(); 
	t.coro.resume();
	
	// destroy() 코드 없음
}

void handle_pitfall_02_use_handle_after_destroy()
{
    Task t = foo();

    t.coro.destroy();   // frame 파괴
	
    t.coro.resume();    	// 잘못된 사용
	bool b = t.coro.done(); // 역시 안됨
}

void handle_pitfall_03_resume_after_done()
{
    Task t = foo();

    t.coro.resume(); 
    t.coro.resume(); 
	// 코루틴은 이미 final suspend 에 도달된 상태
	t.coro.resume(); // 잘못된 사용
}

void handle_pitfall_04_double_destroy_same_handle()
{
    Task t = foo();

    t.coro.destroy();
    t.coro.destroy();   // 잘못된 사용: 같은 frame 을 두 번 파괴
}

void handle_pitfall_05_double_destroy_with_copied_handle()
{
    Task t = foo();

    std::coroutine_handle<> h1 = t.coro;
    std::coroutine_handle<> h2 = t.coro;   // 같은 frame 을 가리키는 복사본

    h1.destroy();
    h2.destroy();   // 잘못된 사용
}

int main()
{
}









