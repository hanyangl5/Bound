#pragma once

#include "enum.h"

#include "utils/types.h"

namespace bd {
namespace gal {

// concept
//template <typename gal_impl>
//concept gal_interface = requires(gal_impl impl) {
//#ifndef GAL_REQUIRES
//#define GAL_REQUIRES
//#include "helper/helper_macro2.h"
//#undef GAL_REQUIRES
//#endif // GAL_REQUIRES
//};

template <class gal_impl> struct gal_interface {
  public:
#ifndef GAL_INTERFACE
#define GAL_INTERFACE
#include "helper/helper_macro2.h"
#undef GAL_INTERFACE
#endif // GAL_REQUIRES
};

} // namespace gal
} // namespace bd