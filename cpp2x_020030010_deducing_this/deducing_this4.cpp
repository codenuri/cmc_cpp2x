#include <cstring>
#include <type_traits>

class String 
{
	char* ptr;
public:
	String(const char* s) 
	{
		ptr = new char[strlen(s) + 1];
		strcpy(ptr, s);
	}
	~String() { delete[] ptr; }

	//  	  char& operator[](int i)       { return ptr[i];}
 	// const char& operator[](int i) const { return ptr[i];}

//	 	  char& operator[](this String& self, int i)       { return self.ptr[i];}
// 	const char& operator[](this const String& self, int i) { return self.ptr[i];}

	template<typename T>
	auto operator[](this T& self, int i) 
		-> std::conditional_t<std::is_const_v<T>, const char&, char&>
	{ return self.ptr[i];}
};

int main() 
{
	String ss("AAA");
	const String cs("AAA");

	auto a1 = ss[0]; // ok
	auto a2 = cs[0]; // ok
	ss[0] = 'a';	 // ok
//	cs[0] = 'a';	 // error
}

