/*
 * Copyright (c) 2016-2017  Oak Ridge National Laboratory.
 *                          All rights reserved.
 * Copyright (c) 2016-2017  UT-Battelle, LLC.
 *                          All rights reserved.
 *
 * Thomas Naughton <naughtont@ornl.gov>
 *
 * TJN: Debug routines that assume support of C99 variadic macros.
 *      (Ref: https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html)
 *
 * File: "TJN_debug.h"
 */

#ifndef _TJN_DEBUG_H_
#define _TJN_DEBUG_H_


#ifdef __cplusplus
extern "C" {
#endif


/* Enable (1), Disable (0) */
#define DBG_CODE_DEBUG (0)

#include <unistd.h> /* sleep() */


/*
 * Print a debug msg (prefixed with [file:line# function]
 * Usage:
 *   DBG_MSG("hello");
 *   DBG_MSG("count %d\n", cnt);
 */
#if(DBG_CODE_DEBUG)
  #define DBG_MSG(format, ...)   \
  do {                                 \
      fprintf (stderr, "[%s:%d %s] DBG: "format"\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
  } while(0)
#else
  #define DBG_MSG(dummy, ...)  do {} while(0)
#endif /* DBG_CODE_DEBUG */


/*
 * (Altnerate) Print a debug msg (prefixed with [file:line# function].
 *
 * Unconditionally included (always available) and intended to be used for
 * "one-off/spot check" prints (DO NOT keep these in code!)
 *
 * Usage:
 *   DBG_MSGv2("hello");
 *   DBG_MSGv2("count %d\n", cnt);
 */
#define DBG_MSGv2(format, ...)   \
do {                                 \
    fprintf (stderr, "[%s:%d %s] DBG: "format"\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
} while(0)


/*
 * Sleep N seconds (prefixed with [file:line# function]).
 * Usage:
 *   DBG_SLEEP(n);
 */
#if(DBG_CODE_DEBUG)
  #define DBG_SLEEP(nsec)   \
  do {                                 \
      fprintf (stderr, "[%s:%d %s] DBG: Sleep %d seconds...\n", __FILE__, __LINE__, __func__, nsec); \
      sleep(nsec); \
      fprintf (stderr, "[%s:%d %s] DBG: DONE SLEEPING.\n", __FILE__, __LINE__, __func__); \
  } while(0)
#else
  #define DBG_SLEEP(dummy)  do {} while(0)
#endif /* DBG_CODE_DEBUG */


#if(DBG_CODE_DEBUG)
  #define DBG_FUNC_ENTER(dummy)                                                           \
  do {                                                                                    \
      fprintf (stderr, "\n\n[%s:%d] DBG: >> FUNC ENTER - %s\n", __FILE__, __LINE__, __func__);\
  } while(0)
#else
  #define DBG_FUNC_ENTER(dummy)  do {} while(0)
#endif /* DBG_CODE_DEBUG */



#if(DBG_CODE_DEBUG)
  #define DBG_FUNC_EXIT(dummy)                                                            \
  do {                                                                                    \
      fprintf (stderr, "[%s:%d] DBG: << FUNC EXIT  - %s\n\n", __FILE__, __LINE__, __func__);\
  } while(0)
#else
  #define DBG_FUNC_EXIT(dummy) do {} while(0)
#endif /* DBG_CODE_DEBUG */


#ifdef __cplusplus
} /* extern C */
#endif

#endif  /* _TJN_DEBUG_H_ */
