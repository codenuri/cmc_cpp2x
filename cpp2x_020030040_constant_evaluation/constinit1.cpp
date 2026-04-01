int add(int a, int b) { return a + b; }

int g1 = 3;			// ok
int g2 = add(1, 2);	// ok

constinit int g3 = 3; 		  // ok
constinit int g4 = add(1, 2); // error
constinit int g5;			  // ok

int main()
{
	constinit int n1 = 3; 		 // error
	constinit static int n2 = 3; // ok
}
