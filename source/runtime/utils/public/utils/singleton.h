#pragma once

// standard libraries
#include <type_traits>

// third party libraries

// project headers
#include "cxx_helper.h"
namespace bd {

template <typename T> class singleton {
  public:
    singleton() = default;
    virtual ~singleton() noexcept = default;

    DELETE_COPY_MOVE(singleton)

    static T &get() noexcept(std::is_nothrow_constructible<T>::value) {
        static T instance;
        initialized = true;
        return instance;
    }

  protected:
    static inline bool initialized = false;
};

} // namespace bd