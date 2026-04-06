import std;

int main()
{
	std::vector v{1,2,3,4,5};

	std::println("{}", v);
}

// 표준 모듈 인터페이스 빌드
// cl /std:c++latest /EHsc /c "%VCToolsInstallDir%\modules\std.ixx"

// 현재 소스 빌드
// cl /std:c++latest /EHsc std_module.cpp std.obj