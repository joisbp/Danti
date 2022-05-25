#pragma once

#include "core/PlatformDefines.h"
#include <iostream>
#include <windows.h>
#include "core/Asserts.h"

enum LogLevels : byte
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

DAPI void LogMessage(LogLevels logLevel, const char* message, ...);

#define LOG_ERROR(message, ...) LogMessage(LogLevels::LERROR, message, ##__VA_ARGS__)

#if ENABLE_WARNING
#define LOG_WARNING(message, ...) LogMessage(LogLevels::LWARNING, message, ##__VA_ARGS__)
#else
#define LOG_WARNING(message, ...)
#endif

#if ENABLE_DEBUG
#define LOG_DEBUG(message, ...) LogMessage(LogLevels::LDEBUG, message, ##__VA_ARGS__)
#else
#define LOG_DEBUG(message, ...)
#endif

#if ENABLE_INFO
#define LOG_INFO(message, ...) LogMessage(LogLevels::LINFO, message, ##__VA_ARGS__)
#else
#define LOG_INFO(message, ...)
#endif

auto blue = [](std::ostream &s) -> std::ostream &
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    return s;
};

auto green = [](std::ostream &s) -> std::ostream &
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    return s;
};

auto red = [](std::ostream &s) -> std::ostream &
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);

    return s;
};

auto yellow = [](std::ostream &s) -> std::ostream &
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    return s;
};

auto pink = [](std::ostream &s) -> std::ostream &
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    return s;
};

auto white = [](std::ostream &s) -> std::ostream &
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    return s;
};

inline void outputAssert(const char *expr, const char *message, const char *file, i32 line)
{
    LOG_ERROR("Assert at: %s \n Assert Message : %s\n File : %s \n Line: %d \n", expr, message, file, line);
}