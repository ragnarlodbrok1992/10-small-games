#ifndef _H_PAD
#define _H_PAD

#include <SDL2/SDL.h>
#include <stdint.h>


#include "geometry.hpp"
#include "../rendering/renderinfo.hpp"
#include "../configuration/consts.hpp"

constexpr int PAD_X_SIZE = 100;
constexpr int PAD_Y_SIZE = 20;
constexpr int PAD_X = (int)((SCREEN_WIDTH / 2) - (PAD_X_SIZE / 2));
constexpr int PAD_Y = (int) (SCREEN_HEIGHT * 0.9);
constexpr int PAD_SPEED = 5;

// Structures

typedef struct {
  // @TODO: Put geometry here as a member
  RectGeometry geo;
  RenderInfo render_info;

} Pad;

typedef struct {
  // UP - 8 | DOWN - 4 | LEFT - 2 | RIGHT - 1
  uint8_t controls;
} PadControls;

// Functions
void init_pad(Pad* pad, int x, int y, int size_x, int size_y, Color color);
void render_pad(SDL_Renderer* renderer, Pad* pad);
void simulate_pad(Pad* pad, PadControls* pad_controls);

#endif /* _H_PAD */

