#include <print>
#include <string>
#include <string_view>

int main()
{
    std::string s = "file_name.txt";
    std::string_view sv = s;

    std::println("{}", s.starts_with("hello"));   // false
    std::println("{}", s.ends_with(".txt"));      // true

    std::println("{}", sv.starts_with("hello"));  // false
    std::println("{}", sv.ends_with(".txt"));     // true
}