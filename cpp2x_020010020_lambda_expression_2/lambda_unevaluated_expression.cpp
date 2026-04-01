int add(int a, int b) { return a + b;};

int main()
{
	int  n = sizeof   ( add(1, 2) ); // add(1, 2) 결과값의 크기
	bool b = noexcept ( add(1, 2) ); // add(1, 2) 처럼 사용시 예외여부
	using T = decltype( add(1, 2) ); // add(1, 2) 결과값의 타입


	using T1 = decltype( [](int a, int b){ return a + b;} );
				// C++20 부터 가능

	// 아래 처럼 사용하면 C++20 이전도 가능
	auto add1 = [](int a, int b){ return a + b;};
	using T2 = decltype(add1);				

}

