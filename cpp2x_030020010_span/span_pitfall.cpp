#include <print>
#include <vector>
#include <span>

int main()
{
	std::span<int> sp1;
	{
		int x[5]{1, 2, 3, 4, 5};
		
		sp1 = x;
	
	}	// <= x 배열 파괴

	auto n1 = sp1[0]; // UB(Undefined Behavior)
	//---------------------------------------------
	std::vector v{1, 2, 3};

	std::span<int> sp2{v};
	
	v.resize(10); // 메모리 재할당

	auto n2 = sp2[0]; // UB
}
