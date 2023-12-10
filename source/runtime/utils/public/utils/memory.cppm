//--------------------------------------------------------------------------------------------
// NOTE: Make sure this is the last include in a .cpp file!
//       Never include this file from a header!!  If you must use the mem manager from a
//       header (which should be in rare cases, and usually only in core Forge source),
//       define "IMEMORY_FROM_HEADER" before including it.
//--------------------------------------------------------------------------------------------
module;

export module utils:memory;

import :types;

export namespace bd {

constexpr uint64 BD_KB = 1024ull;
constexpr uint64 BD_MB = 1024ull * BD_KB;
constexpr uint64 BD_GB = 1024ull * BD_KB;

// void *bd_malloc_internal(size_t size, const char *f, int l, const char *sf);
// void *bd_memalign_internal(size_t align, size_t size, const char *f, int l, const char *sf);
// void *bd_calloc_internal(size_t count, size_t size, const char *f, int l, const char *sf);
// void *bd_calloc_memalign_internal(size_t count, size_t align, size_t size, const char *f, int l, const char *sf);
// void *bd_realloc_internal(void *ptr, size_t size, const char *f, int l, const char *sf);
// void bd_free_internal(void *ptr, const char *f, int l, const char *sf);

// template <typename T, typename... Args> static T *bd_placement_new(void *ptr, Args &&...args) {
//     return new (ptr) T(std::forward<Args>(args)...);
// }

// template <typename T, typename... Args>
// static T *bd_new_internal(const char *f, int l, const char *sf, Args &&...args) {
//     T *ptr = (T *)bd_memalign_internal(alignof(T), sizeof(T), f, l, sf);
//     return bd_placement_new<T>(ptr, std::forward<Args>(args)...);
// }

// template <typename T> static void bd_delete_internal(T *ptr, const char *f, int l, const char *sf) {
//     if (ptr) {
//         ptr->~T();
//         bd_free_internal(ptr, f, l, sf);
//     }
// }

// #ifndef bd_malloc
// #define bd_malloc(size) bd_malloc_internal(size, __FILE__, __LINE__, __FUNCTION__)
// #endif
// #ifndef bd_memalign
// #define bd_memalign(align, size) bd_memalign_internal(align, size, __FILE__, __LINE__, __FUNCTION__)
// #endif
// #ifndef bd_calloc
// #define bd_calloc(count, size) bd_calloc_internal(count, size, __FILE__, __LINE__, __FUNCTION__)
// #endif
// #ifndef bd_calloc_memalign
// #define bd_calloc_memalign(count, align, size)                                                                         \
//     bd_calloc_memalign_internal(count, align, size, __FILE__, __LINE__, __FUNCTION__)
// #endif
// #ifndef bd_realloc
// #define bd_realloc(ptr, size) bd_realloc_internal(ptr, size, __FILE__, __LINE__, __FUNCTION__)
// #endif
// #ifndef bd_free
// #define bd_free(ptr) bd_free_internal(ptr, __FILE__, __LINE__, __FUNCTION__)
// #endif

// #ifndef bd_new
// #define bd_new(ObjectType, ...) bd_new_internal<ObjectType>(__FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
// #endif
// #ifndef bd_delete
// #define bd_delete(ptr) bd_delete_internal(ptr, __FILE__, __LINE__, __FUNCTION__)
// #endif

// #ifndef malloc
// #define malloc(size) static_assert(false, "Please use bd_malloc");
// #endif
// #ifndef calloc
// #define calloc(count, size) static_assert(false, "Please use bd_calloc");
// #endif
// #ifndef memalign
// #define memalign(align, size) static_assert(false, "Please use bd_memalign");
// #endif
// #ifndef realloc
// #define realloc(ptr, size) static_assert(false, "Please use bd_realloc");
// #endif
// #ifndef free
// #define free(ptr) static_assert(false, "Please use bd_free");
// #endif

// #ifndef new
// #define new static_assert(false, "Please use bd_placement_new");
// #endif
// #ifndef delete
// #define delete static_assert(false, "Please use bd_free with explicit destructor call");
// #endif

} // namespace bd