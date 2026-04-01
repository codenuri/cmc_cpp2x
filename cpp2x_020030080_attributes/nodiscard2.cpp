struct MyType
{
    [[nodiscard]]  MyType(int n, bool b) {}
};

int main()
{
    MyType t1{1, true};			 // ok

	MyType t2 = MyType{1, true}; // ok

//	MyType{1, true};			 // warning
}
