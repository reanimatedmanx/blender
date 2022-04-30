/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef GPU_SHADER
#  include "GPU_shader_shared_utils.h"

#  ifdef __cplusplus
extern "C" {
#  else
typedef enum OVERLAY_GridBits OVERLAY_GridBits;
#  endif
typedef struct OVERLAY_GridData OVERLAY_GridData;
#endif

enum OVERLAY_GridBits {
  SHOW_AXIS_X = (1 << 0),
  SHOW_AXIS_Y = (1 << 1),
  SHOW_AXIS_Z = (1 << 2),
  SHOW_GRID = (1 << 3),
  PLANE_XY = (1 << 4),
  PLANE_XZ = (1 << 5),
  PLANE_YZ = (1 << 6),
  CLIP_ZPOS = (1 << 7),
  CLIP_ZNEG = (1 << 8),
  GRID_BACK = (1 << 9),
  GRID_CAMERA = (1 << 10),
  PLANE_IMAGE = (1 << 11),
  CUSTOM_GRID = (1 << 12),
};

/* Match: #SI_GRID_STEPS_LEN */
#define OVERLAY_GRID_STEPS_LEN 8

struct OVERLAY_GridData {
  float4 steps[OVERLAY_GRID_STEPS_LEN]; /* float arrays are padded to float4 in std130. */
  float4 size;                          /* float3 padded to float4. */
  float distance;
  float line_size;
  float zoom_factor; /* Only for UV editor */
  float _pad0;
};
BLI_STATIC_ASSERT_ALIGN(OVERLAY_GridData, 16)

#ifdef GPU_SHADER
/* Keep the same values as in `draw_cache_imp_curve.c` */
#  define ACTIVE_NURB (1 << 2)
#  define BEZIER_HANDLE (1 << 3)
#  define EVEN_U_BIT (1 << 4)
#  define COLOR_SHIFT 5

/* Keep the same value in `handle_display` in `DNA_view3d_types.h` */
#  define CURVE_HANDLE_SELECTED 0
#  define CURVE_HANDLE_ALL 1
#else
/* TODO(fclem): Find a better way to share enums/defines from DNA files with GLSL. */
BLI_STATIC_ASSERT(CURVE_HANDLE_SELECTED == 0, "Ensure value is sync");
BLI_STATIC_ASSERT(CURVE_HANDLE_ALL == 1, "Ensure value is sync");
#endif

#ifndef GPU_SHADER
#  ifdef __cplusplus
}
#  endif
#endif
