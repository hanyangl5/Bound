#include <cstdio>
#include <stdexcept>

#include <utils/log.h>
#include <stl/containers.h>

constexpr bd::stl::str default_logger1 = "B21D";
int main() {
      bd::Log::log(default_logger1, bd::Log::loglevel::warn, "dasffsad");
    // stl
    // 
    // bd::stl::vector<int> arr{1};
    // std::printf("%d", arr.at(3));
    // exception
    //throw std::exception("test");
    // rtti
    //typeid(x);
}