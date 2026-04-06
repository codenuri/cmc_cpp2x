#include <mdspan>
#include <print>
#include <vector>
#include <cstddef>

// custom accessor
template<typename T>
struct logging_accessor
{
    using element_type = T;
    using reference = T&;
    using data_handle_type = T*;
    using offset_policy = logging_accessor<T>;

    logging_accessor() = default;

    template<typename U>
    constexpr logging_accessor(const logging_accessor<U>&) noexcept
    {}

    constexpr reference access(data_handle_type p, std::size_t i) const noexcept
    {
        std::println("[log] access index = {}, value = {}", i, p[i]);
        return p[i];
    }

    constexpr data_handle_type offset(data_handle_type p, std::size_t i) const noexcept
    {
        return p + i;
    }
};

int main()
{
    int x[6] = { 10, 20, 30, 40, 50, 60 };

	std::mdspan<int, 
				std::extents<std::size_t, 2, 3>, 
				std::layout_right, 
				logging_accessor<int> > ms{x};

	std::println("ms[0, 0] = {}", ms[0, 0]);

    ms[1, 2] = 999;
}
