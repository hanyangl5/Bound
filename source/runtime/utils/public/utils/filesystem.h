#pragma once
#include <filesystem>

namespace bd {
namespace fs {
using path = std::filesystem::path;
void create_directory(const path &p);
} // namespace fs
} // namespace bd