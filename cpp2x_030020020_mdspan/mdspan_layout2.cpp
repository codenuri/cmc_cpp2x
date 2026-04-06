#include <array>
#include <print>
#include <mdspan>

int main()
{
    int x[12]{ 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0 };

	// 2개의 동적 크기 타입
	using myextent = std::dextents<std::size_t, 2>;

    std::layout_stride::mapping<myextent> m{ myextent{ 2, 3 },	// 2, 3 의 동적크기정보를 담은 객체
        								  	   std::array<std::size_t, 2>{6, 2}};
											   						// row 1개 증가시 6칸 이동
																	// col 1개 증가시 2칸 이동
    std::mdspan<int, myextent, std::layout_stride> mds{x, m};
														// mapping 객체 m 을 사용해서 offset 계산
	mds[1, 2] = 100;	// x[10] = 100

    std::println("x[10] = {}", x[10]);
}
