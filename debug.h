#ifndef _debug_h
#define _debug_h

#include <stdio.h>
#include <string.h>
#include <errno.h>

#define explicit_errno() (errno == 0 ? "No error" : strerror(errno))
#define check(condition, msg, ...) if (!(condition)) { err(msg, ##__VA_ARGS__); errno = 0; goto error; }

#define err(msg, ...) fprintf(stderr, "[ERR] [%s-%d] [errno: %s] " msg "\n", __FILE__, __LINE__, explicit_errno(), ##__VA_ARGS__)
#define wrn(msg, ...) fprintf(stderr, "[WRN] [%s-%d] [errno: %s] " msg "\n", __FILE__, __LINE__, explicit_errno(), ##__VA_ARGS__)
#define inf(msg, ...) fprintf(stderr, "[INF] [%s-%d] " msg "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#ifdef NDEBUG
#define dbg(msg, ...)
#else
#define dbg(msg, ...) fprintf(stderr, "[DBG] [%s-%d] " msg "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#endif //_debug_h