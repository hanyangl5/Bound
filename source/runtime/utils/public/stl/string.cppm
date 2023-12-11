module;

#include <string>
export module string;

export namespace bd {
    namespace stl {
    using str = std::pmr::string;
    using wstr = std::pmr::wstring;
    } // namespace stl
} // namespace bd
