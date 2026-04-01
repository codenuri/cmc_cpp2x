template<typename... Ts>
auto make_lambda(Ts... xs)
{
	// Pack expansion in Init-capture - C++20
    return [...vals = xs]()
    {
        return sizeof...(vals);
    };
}

// static lambda - C++23
auto f = [] static (int x)
{
    return x * 2;
};

// recursive lambda using explicit object parameter - C++23
auto fact = [](this auto&& self, int n) -> int
{
    return n <= 1 ? 1 : n * self(n - 1);
};

int main()
{

}
