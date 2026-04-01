int main()
{
	int n = 10;

	auto f1 = [n](int a) { return a + n;};
	auto f2 = [ ](int a) { return a;};
	
	
	decltype(f1) a = f1;	// ok
	decltype(f1) b;			// error

	decltype(f2) c = f2;	// ok
	decltype(f2) d;			// C++20 이후 ok
}
