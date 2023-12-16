#pragma  once
#include <memory>
#include <source_location>

#include "cxx_helper.h"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>


#include "types.h"
#include <stl/containers.h>
namespace bd {

constexpr bd::stl::str default_logger = "BD";

class Log {
  public:
    enum class loglevel : uint8 { debug, info, warn, error, critical };
    consteval spdlog::level::level_enum to_spdlog_loglevel(loglevel level) {
        switch (level) {
        case bd::Log::loglevel::debug:
            return spdlog::level::debug;
        case bd::Log::loglevel::info:
            return spdlog::level::info;
        case bd::Log::loglevel::warn:
            return spdlog::level::warn;
        case bd::Log::loglevel::error:
            return spdlog::level::err;
        case bd::Log::loglevel::critical:
            return spdlog::level::critical;
        default:
            //static_assert(false);
            return spdlog::level::n_levels;
        }
    }
    Log() = delete;
    ~Log() = delete;
    DELETE_COPY_MOVE(Log);

    template <typename... Args>
    static constexpr void log(const bd::stl::str &logger, loglevel level, spdlog::format_string_t<Args...> fmt,
                              Args &&...args) noexcept {
        constexpr std::source_location loc = std::source_location::current();
        constexpr spdlog::source_loc spdlog_loc{loc.file_name(), (int32)loc.line(), loc.function_name()};
        // create logger on demand
        if (spdlog::get(logger) == nullptr) {
            spdlog::stdout_color_mt(logger);
        }
        spdlog::get(logger)->log(spdlog_loc, spdlog::level::warn, fmt, std::forward<Args>(args)...);
    }

    // add custuom logger
    static void add_logger(const bd::stl::str &logger) { spdlog::stdout_color_mt(bd::stl::str(logger)); }
};

using loglevel = Log::loglevel;

//inline std::string HrToString(long hr) {
//    char s_str[64] = {};
//    sprintf_s(s_str, "HRESULT of 0x%08X", static_cast<u32>(hr));
//    return std::string(s_str);
//}

//#define CHECK_VK_RESULT(res) bd::Log::get().CheckVulkanResult(res, __FUNCTION__, __LINE__);
//
//#define CHECK_DX_RESULT(res) bd::Log::get().CheckDXResult(res, __FUNCTION__, __LINE__);

} // namespace bd
