#include <print>

#if __has_include(<optional>)
    #include <optional>
    #define HAS_STD_OPTIONAL 1
#else
    #define HAS_STD_OPTIONAL 0
#endif

#if __has_include("my_config.hpp")
    #include "my_config.hpp"
#else
    #error "my_config.hpp not found"
#endif

int main()
{

}