int foo(int i) 
{
    if  ( i >  0) [[likely]]
        i += 2; 
    else 
        i -= 2; 

    return i; 
} 

int main() 
{ 
    auto ret = foo(10);
}