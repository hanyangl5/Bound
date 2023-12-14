/*
 * Code adapted from ConfettiFX The-Forge
 * 
 * Copyright (c) 2017-2022 The Forge Interactive Inc.
 *
 * This file is part of The-Forge
 * (see https://github.com/ConfettiFX/The-Forge).
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
*/

#include <algorithm>
#include <optional>

#include <vulkan/vulkan.h>

#define VMA_RECORDING_ENABLED 1
#define VMA_STATIC_VULKAN_FUNCTIONS 0
#define VMA_DYNAMIC_VULKAN_FUNCTIONS 1
#define VMA_IMPLEMENTATION 1

#ifndef NDEBUG
#ifndef VMA_DEBUG_LOG_FORMAT
#define VMA_DEBUG_LOG_FORMAT(format, ...)
/*
   #define VMA_DEBUG_LOG_FORMAT(format, ...) do { \
       printf((format), __VA_ARGS__); \
       printf("\n"); \
   } while(false)
   */
#endif

#ifndef VMA_DEBUG_LOG
#define VMA_DEBUG_LOG(str) VMA_DEBUG_LOG_FORMAT("%s", (str))
#endif
#endif // NDEBUG
#include <vk_mem_alloc.h>

#include "../enum.h"
#include "framework/utils/blob/blob.h"
#include "framework/utils/input/input.h"
#include "framework/utils/io/file_system.h"
import log
#include "framework/utils/math/math.h"
#include "framework/utils/memory/container.h"

#include "gal_vulkan.h"
#include "gal_vulkan_enum.h"
#include "gal_vulkan_utils.h"

#include "../shader/shader_compiler.h"

#define ANT_VK_API_VERSION VK_API_VERSION_1_3

namespace bd::gal {

} // namespace bd::gal
