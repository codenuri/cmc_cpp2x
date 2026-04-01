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
	int a[2][2] = {0};
	Matrix m;

	int n1 = a[0][0]; // ✅ ok
	int n2 = m[0, 0]; // ✅ ok

	int n3 = a[0, 0]; // 🚨 error
	int n4 = m[0][0]; // 🚨 error
}
