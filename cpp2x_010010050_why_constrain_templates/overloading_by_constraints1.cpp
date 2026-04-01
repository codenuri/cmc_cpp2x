template<typename T>
void f1(T a) {}			// #1

template<typename T>
void f1(T a, T b) {}	// #2

template<typename T>
void f2(T a, T b) {}	// #3

template<typename T1, typename T2>
void f2(T1 a, T2 b) {}	// #4

int main() {
	f1(1);		// #1
	f1(1, 2);	// #2

	f2(1, 2); 	// #3
	f2(1, 2.1); // #4
}