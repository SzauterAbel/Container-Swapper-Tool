#ifndef LOG_HPP
#define LOG_HPP
#include "Config.hpp"
#include <spdlog/common.h>
#include <spdlog/spdlog.h>

template <typename... Args>
inline void log_info(const char *fmt, Args &&...args) {
  spdlog::info(fmt, std::forward<Args>(args)...);
}
template <typename... Args>
inline void log_error(const char *fmt, Args &&...args) {
  spdlog::error(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
static inline void log_debug(const char *fmt, Args &&...args) {
  if (Config::getInstance()->getVerbose()) {
    spdlog::debug(fmt, std::forward<Args>(args)...);
  }
}

#endif // LOG_HPP