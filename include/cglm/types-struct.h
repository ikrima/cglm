/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_types_struct_h
#define cglm_types_struct_h

#ifdef CGLM_ES2_STRUCT_OVERRIDE
#include "es2core/es2_types_math.h"

typedef es2::Vec2_t vec2s;
typedef es2::Vec3_t vec3s;
typedef es2::Vec4_t vec4s;
typedef es2::Quat_t versors;
typedef es2::Mat2_t mat2s;
typedef es2::Mat3_t mat3s;
typedef es2::Mat4_t mat4s;
#else
#include "types.h"

/*
 * Anonymous structs are available since C11, but we'd like to be compatible
 * with C99 and C89 too. So let's figure out if we should be using them or not.
 * It's simply a convenience feature, you can e.g. build the library with
 * anonymous structs and your application without them and they'll still be
 * compatible, cglm doesn't use the anonymous structs internally.
 */
#ifndef CGLM_USE_ANONYMOUS_STRUCT
   /* If the user doesn't explicitly specify if they want anonymous structs or
    * not, then we'll try to intuit an appropriate choice. */
#  if defined(CGLM_NO_ANONYMOUS_STRUCT)
     /* The user has defined CGLM_NO_ANONYMOUS_STRUCT. This used to be the
      * only #define governing the use of anonymous structs, so for backward
      * compatibility, we still honor that choice and disable them. */
#    define CGLM_USE_ANONYMOUS_STRUCT 0
#  elif __STDC_VERSION__ >= 20112L || defined(_MSVC_VER)
     /* We're compiling for C11 or this is the MSVC compiler. In either
      * case, anonymous structs are available, so use them. */
#    define CGLM_USE_ANONYMOUS_STRUCT 1
#  elif defined(_MSC_VER) && (_MSC_VER >= 1900) /*  Visual Studio 2015 */
     /* We can support anonymous structs
      * since Visual Studio 2015 or 2017 (1910) maybe? */
#    define CGLM_USE_ANONYMOUS_STRUCT 1
#  else
     /* Otherwise, we're presumably building for C99 or C89 and can't rely
      * on anonymous structs being available. Turn them off. */
#    define CGLM_USE_ANONYMOUS_STRUCT 0
#  endif
#endif

typedef union vec2s {
  vec2 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float x;
    float y;
  };
#endif
#ifdef CGLM_VEC2_CLASS_EXTRA
  CGLM_VEC2_CLASS_EXTRA
#endif
} vec2s;

typedef union vec3s {
  vec3 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float x;
    float y;
    float z;
  };
#endif
#ifdef CGLM_VEC3_CLASS_EXTRA
  CGLM_VEC3_CLASS_EXTRA
#endif
} vec3s;

typedef union ivec3s {
  ivec3 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    int x;
    int y;
    int z;
  };
#endif
#ifdef CGLM_VEC3I_CLASS_EXTRA
  CGLM_VEC3I_CLASS_EXTRA
#endif
} ivec3s;

typedef union CGLM_ALIGN_IF(16) vec4s {
  vec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float x;
    float y;
    float z;
    float w;
  };
#endif
#ifdef CGLM_VEC4_CLASS_EXTRA
  CGLM_VEC4_CLASS_EXTRA
#endif
} vec4s;

typedef union CGLM_ALIGN_IF(16) versors {
  vec4 raw;
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float x;
    float y;
    float z;
    float w;
  };

  struct {
    vec3s imag;
    float real;
  };
#endif
#ifdef CGLM_VERSORS_CLASS_EXTRA
  CGLM_VERSORS_CLASS_EXTRA
#endif
} versors;

typedef union mat2s {
  mat2  raw;
  vec2s col[2];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01;
    float m10, m11;
  };
#endif
#ifdef CGLM_MAT2_CLASS_EXTRA
  CGLM_MAT2_CLASS_EXTRA
#endif
} mat2s;

typedef union mat3s {
  mat3  raw;
  vec3s col[3];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
  };
#endif
#ifdef CGLM_MAT3_CLASS_EXTRA
  CGLM_MAT3_CLASS_EXTRA
#endif
} mat3s;

typedef union CGLM_ALIGN_MAT mat4s {
  mat4  raw;
  vec4s col[4];
#if CGLM_USE_ANONYMOUS_STRUCT
  struct {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
  };
#endif
#ifdef CGLM_MAT4_CLASS_EXTRA
  CGLM_MAT4_CLASS_EXTRA
#endif
} mat4s;
#endif

#endif /* cglm_types_struct_h */
