module;

#include <cstdint>

export module types;

export namespace bd {
using uint8 = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;

using int8 = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;

using float32 = float;
using float64 = double;

template <typename T> T _min(const T &lhs, const T &rhs) { return lhs < rhs ? lhs : rhs; }

template <typename T> T _max(const T &lhs, const T &rhs) { return lhs > rhs ? lhs : rhs; }

template <typename T> T constexpr _lerp(const T &lhs, const T &rhs, float32 t) { return lhs + t * (rhs - lhs); }

template <typename T> T constexpr AlignUp(const T &lhs, const T &rhs) { return (lhs + T(rhs - 1)) / rhs; }

} // namespace bd