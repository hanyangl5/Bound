// Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
//
// This file is part of the AMD Render Pipeline Shaders SDK which is
// released under the AMD INTERNAL EVALUATION LICENSE.
//
// See file LICENSE.txt for full license details.

#include "render/rps/runtime/common/rps_runtime.h"
#include "runtime/common/rps_render_graph.hpp"

RPS_STATIC_ASSERT_STANDALONE(RPS_SEMANTIC_USER_RESOURCE_BINDING + 1 == RPS_SEMANTIC_COUNT,
                             "RPS_SEMANTIC_USER_RESOURCE_BINDING must be the last valid element of RpsSemantic",
                             RpsSemantic);
