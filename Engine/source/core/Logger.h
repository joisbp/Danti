#include "PlatformDefines.h"
#include <string>

enum class LogLevels
{
    LERROR = 0,
    LWARNING,
    LDEBUG,
    LINFO
};

#define ENABLE_WARNING 1
#define ENABLE_DEBUG 1
#define ENABLE_INFO 1

#ifdef RELEASE
#define ENABLE_WARNING 0
#define ENABLE_DEBUG 0
#define ENABLE_INFO 0
#endif

DAPI void LogMessage(LogLevels logLevel, std::string message, ...);

#define LOG_ERROR(message, ...) LogMessage(LogLevels::LERROR, message, ##__VA_ARGS__)

#ifdef ENABLE_WARNING
#define LOG_WARNING(message, ...) LogMessage(LogLevels::LWARNING, message, ##__VA_ARGS__)
#else
#define LOG_WARNING(message, ...)
#endif

#ifdef ENABLE_DEBUG
#define LOG_DEBUG(message, ...) LogMessage(LogLevels::LDEBUG, message, ##__VA_ARGS__)
#else
#define LOG_DEBUG(message, ...)
#endif

#ifdef ENABLE_INFO
#define LOG_INFO(message, ...) LogMessage(LogLevels::LINFO, message, ##__VA_ARGS__)
#else
#define LOG_INFO(message, ...)
#endif
