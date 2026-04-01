#include <concepts>
#include <string>
using namespace std::literals;

template<typename T> class Wrapper
{
    T data;
public:
    explicit( std::integral<T> ) Wrapper(T value) 
				: data{value} {}
};
int main()
{
    Wrapper w1("abcd"s);     // ✅ ok
	Wrapper w2 = "abcd"s;    // ✅ ok
    Wrapper w3{"abcd"s};	 // ✅ ok
    Wrapper w4 = {"abcd"s};  // ✅ ok

    w1 = "xyz"s; // implicit conversion ✅ ok

    Wrapper w5{10};  // ✅ ok
	Wrapper w6 = 10; // 🚨 error
}