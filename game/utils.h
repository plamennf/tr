#ifndef UTILS_H
#define UTILS_H

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))
#define SQUARE(x) ((x)*(x))

#ifdef _DEBUG
#define ASSERT(expr) if (expr) {} else { __debugbreak(); }
#else
#define ASSERT(expr)
#endif

#endif
