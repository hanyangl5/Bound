module;
#include <map>
#include <unordered_map>
export module bdstl:map;

export namespace bd {
    namespace stl {
    template <typename Key, typename Val> using map = std::pmr::map<Key, Val>;
    template <typename Key, typename Val> using multi_map = std::pmr::multimap<Key, Val>;
    template <typename Key, typename Val> using hash_map = std::pmr::unordered_map<Key, Val>;
    template <typename Key, typename Val> using hash_multi_map = std::pmr::unordered_multimap<Key, Val>;

    } // namespace stl
} // namespace bd
