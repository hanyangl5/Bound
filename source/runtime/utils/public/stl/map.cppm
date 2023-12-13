module;
#include <map>
#include <unordered_map>
export module map;

export namespace bd {
    namespace stl {
    template <typename Key, typename Val> using map = std::map<Key, Val>;
    template <typename Key, typename Val> using multi_map = std::multimap<Key, Val>;
    template <typename Key, typename Val> using hash_map = std::unordered_map<Key, Val>;
    template <typename Key, typename Val> using hash_multi_map = std::unordered_multimap<Key, Val>;

    } // namespace stl
} // namespace bd
