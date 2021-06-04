/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_common_h
#define cglm_common_h

#ifdef CGLM_USER_CONFIG
  #include CGLM_USER_CONFIG
  #include "es2core/math/es2scalar.h"
#else
  #ifndef _USE_MATH_DEFINES
    #define _USE_MATH_DEFINES /* for windows */
  #endif

  #ifndef _USE_MATH_DEFINES
  #  define _USE_MATH_DEFINES       /* for windows */
  #endif

  #ifndef _CRT_SECURE_NO_WARNINGS
  #  define _CRT_SECURE_NO_WARNINGS /* for windows */
  #endif

  #include <stdint.h>
  #include <stddef.h>
  #include <math.h>
  #include <float.h>
  #include <stdbool.h>

  #define glm_fabsf(_a)      fabsf(_a)
  #define glm_isnan(_a)      isnan(_a)
  #define glm_isinf(_a)      isinf(_a)
  #define glm_fminf(_a, _b)  fminf(_a, _b)
  #define glm_floorf(_a)     floorf(_a)
  #define glm_sqrtf(_a)      sqrtf(_a)
  #define glm_powf(_a, _b)   powf(_a, _b)
  #define glm_sinf(_a)       sinf(_a)
  #define glm_cosf(_a)       cosf(_a)
  #define glm_tanf(_a)       tanf(_a)
  #define glm_asinf(_a)      asinf(_a)
  #define glm_acosf(_a)      acosf(_a)
  #define glm_atan2f(_a, _b) atan2f(_a, _b)

  #if defined(_MSC_VER)
  #  ifdef CGLM_STATIC
  #    define CGLM_EXPORT
  #  elif defined(CGLM_EXPORTS)
  #    define CGLM_EXPORT __declspec(dllexport)
  #  else
  #    define CGLM_EXPORT __declspec(dllimport)
  #  endif
  #  define CGLM_INLINE __forceinline
  #else
  #  define CGLM_EXPORT __attribute__((visibility("default")))
  #  define CGLM_INLINE static inline __attribute((always_inline))
  #endif

  #ifndef CGLM_USE_DEFAULT_EPSILON
  #  ifndef GLM_FLT_EPSILON
  #    define GLM_FLT_EPSILON 1e-6
  #  endif
  #else
  #  define GLM_FLT_EPSILON FLT_EPSILON
  #endif

#endif

#define GLM_SHUFFLE4(z, y, x, w) (((z) << 6) | ((y) << 4) | ((x) << 2) | (w))
#define GLM_SHUFFLE3(z, y, x)    (((z) << 4) | ((y) << 2) | (x))

#include "types.h"
#include "simd/intrin.h"

/*
* Clip control: define GLM_FORCE_DEPTH_ZERO_TO_ONE before including
* CGLM to use a clip space between 0 to 1.
* Coordinate system: define GLM_FORCE_LEFT_HANDED before including
* CGLM to use the left handed coordinate system by default.
*/

#define CGLM_CLIP_CONTROL_ZO_BIT (1 << 0) /* ZERO_TO_ONE */
#define CGLM_CLIP_CONTROL_NO_BIT (1 << 1) /* NEGATIVE_ONE_TO_ONE */
#define CGLM_CLIP_CONTROL_LH_BIT (1 << 2) /* LEFT_HANDED, For DirectX, Metal, Vulkan */
#define CGLM_CLIP_CONTROL_RH_BIT (1 << 3) /* RIGHT_HANDED, For OpenGL, default in GLM */

#define CGLM_CLIP_CONTROL_LH_ZO (CGLM_CLIP_CONTROL_LH_BIT | CGLM_CLIP_CONTROL_ZO_BIT)
#define CGLM_CLIP_CONTROL_LH_NO (CGLM_CLIP_CONTROL_LH_BIT | CGLM_CLIP_CONTROL_NO_BIT)
#define CGLM_CLIP_CONTROL_RH_ZO (CGLM_CLIP_CONTROL_RH_BIT | CGLM_CLIP_CONTROL_ZO_BIT)
#define CGLM_CLIP_CONTROL_RH_NO (CGLM_CLIP_CONTROL_RH_BIT | CGLM_CLIP_CONTROL_NO_BIT)

#ifdef CGLM_FORCE_DEPTH_ZERO_TO_ONE
#  ifdef CGLM_FORCE_LEFT_HANDED
#    define CGLM_CONFIG_CLIP_CONTROL CGLM_CLIP_CONTROL_LH_ZO
#  else
#    define CGLM_CONFIG_CLIP_CONTROL CGLM_CLIP_CONTROL_RH_ZO
#  endif
#else
#  ifdef CGLM_FORCE_LEFT_HANDED
#    define CGLM_CONFIG_CLIP_CONTROL CGLM_CLIP_CONTROL_LH_NO
#  else
#    define CGLM_CONFIG_CLIP_CONTROL CGLM_CLIP_CONTROL_RH_NO
#  endif
#endif

#endif /* cglm_common_h */
