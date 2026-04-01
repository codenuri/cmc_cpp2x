constexpr int add1(int a, int b) 
{ 
	return a + b;
}
consteval int add2(int a, int b) 
{ 
	return a + b;
}
int main()
{
	int a = 2;
	int b = 5;

	constexpr int c1 = add1(2, 5); // ok
	constexpr int c2 = add2(2, 5); // ok

	int n1 = add1(a, b); // ok
//	int n2 = add2(a, b); // error
}
