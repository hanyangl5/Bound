module;
#include <filesystem>
export module filesystem;

export namespace bd {
namespace fs {
using path = std::filesystem::path;
void create_directory(const path& p);
}
} // namespace bd