#include <print>
#include <vector>

struct default_sentinel_t { };

inline constexpr default_sentinel_t default_sentinel;

template<typename Iter>
class counted_iterator
{
    Iter current;
    std::ptrdiff_t cnt;

public:
    counted_iterator(Iter it, std::ptrdiff_t n)
        : current{it}, cnt{n} {}

	std::ptrdiff_t count() { return cnt; }
    auto operator*() const { return *current; }

    counted_iterator& operator++() {
        ++current;
        --cnt;
        return *this;
    }

    friend bool operator==(const counted_iterator& it, default_sentinel_t) {
        return it.cnt == 0;
    }

    friend bool operator!=(const counted_iterator& it, default_sentinel_t s) {
        return !(it == s);
    }
};

int main()
{
    std::vector v{1, 2, 3, 4, 5, 6, 7};

    counted_iterator ci{v.begin(), 5};

	// operator!=(conunted_iterator, default_sentinel_t)
	while ( ci != default_sentinel ) {
		std::print("{}, ", *ci);
		++ci;
	}
}