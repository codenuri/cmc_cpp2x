// #include "mymath.ixx" // C++20 이전 include 방식
import mymath;			 // C++20 에서 도입된 module 방식

int main()
{
	auto a1 = add(10, 3);
	auto a2 = sub(10, 3);
}
// 모듈을 사용하는 코드를 컴파일
// g++ -std=c++20 -fmodules-ts main.cpp mymath.o -o main
// cl /std:c++20 /EHsc main.cpp mymath.obj /reference mymath=.\mymath.ifc /Fe:main.exe