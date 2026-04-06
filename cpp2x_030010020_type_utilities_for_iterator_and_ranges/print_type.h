#include <print>
#include <string>
#include <type_traits>
#include <typeinfo>

template <typename T>
std::string get_type_name()
{
    using Base = std::remove_cvref_t<T>;
    std::string s = typeid(Base).name(); 
    if constexpr (std::is_const_v<std::remove_reference_t<T>>)
        s = "const " + s;

    if constexpr (std::is_volatile_v<std::remove_reference_t<T>>)
        s = "volatile " + s;
    
	if constexpr (std::is_lvalue_reference_v<T>)
        s += "&";
    else if constexpr (std::is_rvalue_reference_v<T>)
        s += "&&";

    return s;
}
