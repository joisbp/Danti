#pragma once

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

typedef float f32;
typedef double f64;

#define TRUE 1
#define FALSE 0

#define STATIC_ASSERT static_assert

#if defined(__WIN64__) || defined(WIN64) || defined(_WIN64)
#define PLATFORM_WINDOWS 1
#endif

#ifdef EXPORT
#ifdef _MSC_VER
#define DAPI __declspec(dllexport)
#endif
#else
#ifdef _MSC_VER
#define DAPI __declspec(dllimport)
#endif
#endif