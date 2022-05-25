#pragma once
#include "core/PlatformDefines.h"
#include <iostream>

#ifdef _MSC_VER
#include <intrin.h>
#define debugbreak() __debugbreak()
#endif
#define ASSERT_ENABLED 0

#if ASSERT_ENABLED
#define DASSERT(expr)                                     \
    if (expr)                                             \
    {                                                     \
    }                                                     \
    else                                                  \
    {                                                     \
        outputAssert(#expr, "", __FILE__, __LINE__);      \
        debugbreak();                                     \
    }                                                     

#define DASSERT_MSG(expr, message) if (expr)              \
    {                                                     \
    }                                                     \
    else                                                  \
    {                                                     \
        outputAssert(#expr, message, __FILE__, __LINE__); \
        debugbreak();                                     \
    }                                                     
#else
#define DASSERT(expr)
#define DASSERT_MSG(expr, message)
#endif