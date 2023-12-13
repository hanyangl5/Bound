#pragma once

import types;

#include "format.h"
// enum included at last
#include "enum.h"

namespace bd::gal {

// intailize gal_context, load function pointer
[[nodiscard]] gal_error_code init_gal(gal_api api, gal_context *context);

#ifndef GAL_FUNCTION_DECLARE
#define GAL_FUNCTION_DECLARE
#include "helper/helper_macro.h"
#undef GAL_FUNCTION_DECLARE
#endif // GAL_FUNCTION_DECLARE

} // namespace bd::gal
