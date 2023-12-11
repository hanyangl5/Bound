module;
#include <set>
#include <unordered_set>
export module set;

export namespace bd {
    namespace stl {
    template <typename Key> using set = std::pmr::set<Key>;
    template <typename Key> using multi_set = std::pmr::multiset<Key>;
    template <typename Key> using hash_set = std::pmr::unordered_set<Key>;
    template <typename Key> using hash_multi_set = std::pmr::unordered_multiset<Key>;

    } // namespace stl
} // namespace bd
