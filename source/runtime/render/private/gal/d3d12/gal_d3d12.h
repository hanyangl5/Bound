#pragma once

// standard libraries
// third party libraries

// project headers
import types;
#include "render/gal/gal.h"

namespace bd::gal {

#define D3D12_FUNCTION_DECLARE
#include "../helper/helper_macro.h"
#undef D3D12_FUNCTION_DECLARE

} // namespace bd::gal
