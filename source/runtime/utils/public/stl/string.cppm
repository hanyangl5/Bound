module;

#include <string>
#include <string_view>
export module string;

export namespace bd {
    namespace stl {
    using str = std::string;
    using wstr = std::wstring;
    using str_view = std::string_view;
    } // namespace stl
} // namespace bd
