#include <cstdio>

import utils;
import bdstl;

auto test_array = []() {
    std::printf("array test\n");
    bd::stl::array<bd::int32, 5> arr{1, 2, 3, 4, 5};
    for (auto &i : arr) {
        std::printf("%d\n", i);
    }
};

auto test_vector = []() {
    std::printf("vector test\n");
    bd::stl::vector<bd::int32> arr;
    for (bd::int32 i = 0; i < 5; i++) {
        arr.push_back(i);
    }
    for (auto &i : arr) {
        std::printf("%d\n", i);
    }
};
auto test_set = []() {
    std::printf("set test\n");
    bd::stl::set<bd::int32> set;
    for (bd::int32 i = 0; i < 5; i++) {
        set.insert(i);
    }
    for (auto &v : set) {
        std::printf("%d\n", v);
    }
};
auto test_map = []() {
    std::printf("map test\n");
    bd::stl::map<bd::int32, bd::int32> map;
    for (bd::int32 i = 0; i < 5; i++) {
        map[i] = i + 1;
    }
    for (auto &[k, v] : map) {
        std::printf("%d %d\n", k, v);
    }
};
auto test_str = []() {
    std::printf("str test\n");
    bd::stl::str str = "12345";
    std::printf("%s\n", str.c_str());
};
int main() {
    test_array();
    test_vector();
    test_set();
    test_map();
    test_str();
}
