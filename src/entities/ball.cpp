#include "ball.hpp"

#include <cmath>

void init_ball(Ball* ball, int x, int y, int radius) {

  ball->geo.x = x;
  ball->geo.y = y;
  ball->geo.radius = radius;
}

void render_ball(SDL_Renderer* renderer, Ball* ball) {
  // Hardcoded color for now
  SDL_SetRenderDrawColor(renderer, 0x24, 0xc1, 0x3b, 0xFF);

  int radius_power = ball->geo.radius * ball->geo.radius;

  for (int a = -ball->geo.radius; a < ball->geo.radius; a++) {
    int hh = (int) std::sqrt(radius_power - a * a);
    int rx = ball->geo.x + a;
    int ph = ball->geo.y + hh;

    for (int b = ball->geo.y - hh; b < ph; b++) {
      // SDL_DrawPixel
      SDL_RenderDrawPoint(renderer, rx, b);
    }
  }
}

