int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
//double gcd(double, double) = delete;
double gcd(double, double) = delete("only integral types are allowed");
int main()
{
	auto ret = gcd(2.3, 3.1);
}