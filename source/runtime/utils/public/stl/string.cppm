module;

#include <string>
export module bdstl:string;

export namespace bd {
    namespace stl {
    using str = std::pmr::string;
    using wstr = std::pmr::wstring;
    } // namespace stl
} // namespace bd
