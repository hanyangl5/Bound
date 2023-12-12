#include <cstdio>
#include <doctest.h>

import platform;
TEST_CASE("test platform") { std::printf("%u", bd::max_thread_count); }