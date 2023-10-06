#ifndef _H_BALL
#define _H_BALL

#include <SDL2/SDL.h>


constexpr int BALL_X = 100;
constexpr int BALL_Y = 100;
constexpr int BALL_RADIUS = 20;
constexpr int BALL_SPEED = 6;

#include "geometry.hpp"
#include "pad.hpp"
#include "../rendering/renderinfo.hpp"
#include "../configuration/consts.hpp"

// Structures
typedef struct {
  RoundGeometry geo;
  RenderInfo render_info;
} Ball;

// Functions
void init_ball(Ball* ball, int x, int y, int radius);
void render_ball(SDL_Renderer* renderer, Ball* ball);
void simulate_ball(Ball* ball, Pad* pad);

#endif /* _H_BALL */

