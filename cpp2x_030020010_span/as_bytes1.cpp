#include <print>
#include <span>

void print_bytes(std::span<const std::byte> sp)
{
	for ( auto e : sp )
		std::print("{:02x}, ", std::to_integer<int>(e));
	std::println();
}

int main()
{
	int x[2]{0x11223344, 0x66778899};

	std::span<int> sp1(x); 
	
	std::span<const std::byte> sp2 = std::as_bytes(sp1);
	
	std::span<std::byte> sp3 = std::as_writable_bytes(sp1);
	
//	sp2[0] = std::byte{0}; // error
	sp3[0] = std::byte{0}; // ok

	print_bytes(sp2);
	print_bytes(sp3);	
}
