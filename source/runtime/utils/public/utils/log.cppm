module;

#include <memory>
#include <spdlog/spdlog.h>

#include "singleton.h"
export module log;

// #define REGISTOR_LOG_CATEGORY(name)

namespace bd {} // namespace bd

#pragma once

import types;
namespace bd {

//inline std::string HrToString(long hr) {
//    char s_str[64] = {};
//    sprintf_s(s_str, "HRESULT of 0x%08X", static_cast<u32>(hr));
//    return std::string(s_str);
//}

class Log : public singleton<Log> {
  public:
    enum class loglevel : u8 { debug, info, warn, error, fatal };

    Log() noexcept;
    ~Log() noexcept override;

    DELETE_COPY_MOVE(Log);

    template <typename... args> inline void debug(args &&..._args) const noexcept {
        m_logger->debug(std::forward<args>(_args)...);
    }

    template <typename... args> inline void info(args &&..._args) const noexcept {
        m_logger->info(std::forward<args>(_args)...);
    }

    template <typename... args> inline void warn(args &&..._args) const noexcept {
        m_logger->warn(std::forward<args>(_args)...);
    }

    template <typename... args> inline void error(args &&..._args) const noexcept {
        m_logger->error(std::forward<args>(_args)...);
    }

  private:
    std::shared_ptr<spdlog::logger> m_logger;
};

Log::Log() noexcept {
    m_logger = spdlog::stdout_color_mt("BD");
    spdlog::set_default_logger(m_logger);
#ifndef NDEBUG
    spdlog::set_level(spdlog::level::debug);
#else
    spdlog::set_level(spdlog::level::info);
#endif // !NDEBUG
}

Log::~Log() noexcept {
    m_logger->flush();
    spdlog::drop_all();
}

#define DECLARE_LOG_CATEGORY ;

#define LOG_DEBUG(...) bd::Log::get().debug(__VA_ARGS__);

#define LOG_INFO(...) bd::Log::get().info(__VA_ARGS__);

#define LOG_WARN(...) bd::Log::get().warn(__VA_ARGS__);

#define LOG_ERROR(...) bd::Log::get().error(__VA_ARGS__);

#define LOG_FATAL(...) bd::Log::get().fatal(__VA_ARGS__);

//#define CHECK_VK_RESULT(res) bd::Log::get().CheckVulkanResult(res, __FUNCTION__, __LINE__);
//
//#define CHECK_DX_RESULT(res) bd::Log::get().CheckDXResult(res, __FUNCTION__, __LINE__);

} // namespace bd