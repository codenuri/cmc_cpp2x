constexpr int add(int a, int b) 
{ 
	return a + b;
}

int main()
{
	int a = 2;
	int b = 5;

	constexpr int c1 = add(2, 5); // ok. compile-time
	constexpr int c2 = add(a, b); // error

	int n = add(a, b); // ok. runtime
}
