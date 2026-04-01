// C++14
#include <map>
#include <string>
#include <string_view>
#include <functional>

int main()
{
    std::map<std::string, int, std::less<>> m = {
        {"apple", 1},
        {"banana", 2},
        {"orange", 3}
    };

	// m.find() 로 "banana" 를 검색하려면 
	// C++14 이전
	std::string key1 = "banana"; // key와 동일한 타입의 객체 필요
	auto it1 = m.find(key1);

	// C++14 이후 
	// key 와 비교가 가능한 타입은 사용가능
 	std::string_view key2 = "banana";
    auto it2 = m.find(key2);  
	 
	auto it3 = m.find("banana");   
}

