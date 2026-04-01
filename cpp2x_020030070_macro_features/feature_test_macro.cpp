#include <print>
#include <version>

int main()
{
    // 언어 특징 지원 여부 조사
#ifdef __cpp_concepts
	std::println("support concepts");
#endif
#ifdef __cpp_modules
	std::println("support modules");
#endif
#ifdef __cpp_pack_indexing
	std::println("support pack indexing");
#endif

    // 라이브러리 특징 지원 여부 조사 - <version> 헤더 필요
#ifdef __cpp_lib_span
	std::println("support span lib");
#endif
#ifdef __cpp_lib_chrono
	std::println("support chrono lib");
    std::println("chrono version : {}", __cpp_lib_chrono);
#endif   
}