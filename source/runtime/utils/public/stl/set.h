#pragma once
#include <set>
#include <unordered_set>


namespace bd {
    namespace stl {
    template <typename Key> using set = std::set<Key>;
    template <typename Key> using multi_set = std::multiset<Key>;
    template <typename Key> using hash_set = std::unordered_set<Key>;
    template <typename Key> using hash_multi_set = std::unordered_multiset<Key>;

    } // namespace stl
} // namespace bd
