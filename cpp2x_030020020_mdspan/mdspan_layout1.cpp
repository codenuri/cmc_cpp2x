#include <print>
#include <vector>
#include <mdspan>

template<typename T>
void print_mdspan(T ms)
{
	for (std::size_t i = 0; i < ms.extent(0); ++i)
	{
		for (std::size_t j = 0; j < ms.extent(1); ++j)
			std::print("{} ", ms[i, j]);
		std::println();
	}
}

int main()
{
	int x[6]{ 0, 1, 2, 3, 4, 5 };

	std::mdspan<int, std::dextents<std::size_t, 2>, std::layout_right> ms1{x, 2, 3};
	std::mdspan<int, std::dextents<std::size_t, 2>, std::layout_left>  ms2{x, 2, 3};

	// [row, col]
	// std::layout_right : row major => row * col_size + col
	// std::layout_left  : col major => col * row_size + row

	std::println("{}", ms1[1, 1]); // x[ 1 * 3 + 1] => x[4] 요소 접근, 4
	std::println("{}", ms2[1, 1]); // x[ 1 * 2 + 1] => x[3] 요소 접근, 3

	print_mdspan(ms1);	// 0, 1, 2
						// 3, 4, 5
						
	print_mdspan(ms2);	// 0, 2, 4
						// 1, 3, 5
}
