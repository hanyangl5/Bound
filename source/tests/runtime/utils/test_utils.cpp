#include <cstdio>

import time;
import filesystem;
import types;
import task;
import log;

auto test_memory = []() {
    // TODO(hyl5):
};

auto test_time = []() {
    auto _1s = bd::time::seconds(1);
    auto _2ms = bd::time::milli(2);
};

auto test_types = []() {
    std::printf("%zu %zu %zu %zu %zu %zu %zu %zu %zu %zu\n", sizeof(bd::uint8), sizeof(bd::uint16), sizeof(bd::uint32),
                sizeof(bd::uint64), sizeof(bd::int8), sizeof(bd::int16), sizeof(bd::int32), sizeof(bd::int64),
                sizeof(bd::float32), sizeof(bd::float64));
};

auto test_task = []() {
    bd::thread ts[10];
    for (bd::int32 i = 0; i < 10; i++) {
        ts[i] = bd::thread([=]() { std::printf("thread %d return\n", i); });
    }

    for (bd::int32 i = 0; i < 10; i++) {
        ts[i].join();
    }
};

auto test_filesystem = []() {
    bd::fs::path p("test_path.txt");
    std::printf("path is %s", p.string().c_str());
};

auto test_log = []() {

};
int main() {
    test_types();
    test_time();
    test_task();
    test_filesystem();
    test_time();
}