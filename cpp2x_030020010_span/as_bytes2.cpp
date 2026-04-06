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
	// int 타입 변수 한개를 byte 단위로 출력
	int n = 4096;

	std::span<int> sp1(&n, 1);		// 배열이나 vector 가 아닌 데이타 1개를 위한 span 만드는 법

	auto sp2 = std::as_bytes(sp1);	// sp2 : std::span<const std::byte>

	print_bytes(sp2);


	struct Packet 
	{
		int header;
		int data;
	};
	// Packet 헤더 분석
	Packet p = { 4096, 0};
	
	print_bytes(std::as_bytes( std::span{&p.header, 1}));
}
