module;

#include <array>
export module array;

export namespace bd {
namespace stl {
template <typename T, std::size_t size> using array = std::array<T, size>;
} // namespace stl
} // namespace bd
