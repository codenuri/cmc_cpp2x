constexpr int c1 = 1;
constinit int c2 = 1;

int main()
{
	c1 = 3; // error
	c2 = 3; // ok
}