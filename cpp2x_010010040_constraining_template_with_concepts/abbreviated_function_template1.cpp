#include <concepts>

void f1(std::integral auto a) {
}

void f2(std::integral auto a) requires (sizeof(a) > 4) {
}

int main() {
	
	f1(3); 		// ok
//	f1(3.4); 	// error
	
//	f2(3); 		// error
	f2(3ll); 	// ok
}