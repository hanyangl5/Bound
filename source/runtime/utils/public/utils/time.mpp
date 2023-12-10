module;

// TODO(hyl5): add https://github.com/HowardHinnant/date
#include <chrono>

export module utils:time;

export namespace bd {
namespace time {

using nano = std::chrono::nanoseconds;
using micro = std::chrono::microseconds;
using milli = std::chrono::milliseconds;
using seconds = std::chrono::seconds;
using minutes = std::chrono::minutes;
using hours = std::chrono::hours;
using days = std::chrono::days;
using weeks = std::chrono::weeks;
using years = std::chrono::years;
using months = std::chrono::months;

template <class Rep, class Period> using duration = std::chrono::duration<Rep, Period>;
} // namespace time
} // namespace bd
