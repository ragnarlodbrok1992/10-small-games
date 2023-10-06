#ifndef _H_RENDERINFO
#define _H_RENDERINFO

#include <stdint.h>

typedef struct {
  uint8_t r, g, b, a;
} Color;

typedef struct {
  Color color;
} RenderInfo;

#endif /* _H_RENDERINFO */

