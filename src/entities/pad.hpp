#ifndef _H_PAD
#define _H_PAD

#include "geometry.hpp"
#include "../rendering/renderinfo.hpp"

// Structures

typedef struct {
  // @TODO: Put geometry here as a member
  RectGeometry geo;
  RenderInfo render_info;

} Pad;

// Functions
void init_pad(Pad* pad, int x, int y, int size_x, int size_y, Color color);

#endif /* _H_PAD */

