#include <print>

struct Matrix
{
    int data[2][3] = {0, 0, 0, 0};

    int& operator[](std::size_t r, std::size_t c)
    {
        return data[r][c];
    }
};

int main()
{
	Matrix m;
	m[0, 0] = 3;
	m[0, 1] = 5;

	std::println("{}", m[0, 1]);	// 5
	std::println("{}", m[1, 1]);	// 0
}
