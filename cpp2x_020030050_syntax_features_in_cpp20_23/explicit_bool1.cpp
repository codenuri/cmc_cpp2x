struct MyType 
{
//	MyType(int a) {}
	explicit MyType(int a) {}

};

void foo(MyType a) {}

int main()
{
	MyType a1(3);	 // direct initialization
	MyType a2 = 3;	 // copy   initialization
	MyType a3{3};	 // direct initialization
	MyType a4 = {3}; // copy   initialization

	foo(3); // int => MyType

}
