// #include "render/gal/gal.h"

// #define DEFINE_GAL_FUNCTION(name) gal_pfn_##name name;

// namespace bd::gal {

// extern gal_error_code vk_init_gal(gal_context *context);

// #ifdef _WIN32
// extern gal_error_code d3d12_init_gal(gal_context *context);
// #endif //  _WIN32

// [[nodiscard]] gal_error_code init_gal(gal_api api, gal_context *context) {
//     switch (api) {
//     case bd::gal::gal_api::UNDEFINED:
//         break;
//     case bd::gal::gal_api::VULKAN:
//         return vk_init_gal(context);
//         break;
//     case bd::gal::gal_api::D3D12:
// #ifdef _WIN32
// #ifndef BD_IGNORE_D3D
//         return d3d12_init_gal(context);
// #endif
//         return gal_error_code::ERR;
    
// #else
//         return gal_error_code::ERR;
// #endif
// default:
//     break;
// }

// return gal_error_code::SUC;
// }

// #define GAL_FUNCTION_DEFINATION
// #include "helper/helper_macro.h"
// #undef GAL_FUNCTION_DEFINATION
// } // namespace bd::gal
