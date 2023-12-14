#pragma once

#include "enum.h"

import types;

namespace bd::gal {

// intailize gal_context, load function pointer
// [[nodiscard]] gal_error_code init_gal(gal_api api, gal_context *context);

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
    //void name() { (static_cast<gal_impl *>(this))->impl(); }
#ifndef GAL_INTERFACE
#define GAL_INTERFACE
#include "helper/helper_macro2.h"
#undef GAL_INTERFACE
#endif // GAL_REQUIRES
};

} // namespace bd::gal
