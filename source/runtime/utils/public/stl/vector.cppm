module;

#include <vector>
export module vector;

export namespace bd {
    namespace stl {
    template <typename T> using vector = std::pmr::vector<T>;
    } // namespace stl
} // namespace bd
