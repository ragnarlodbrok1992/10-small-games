#include "ball.hpp"

#include "../configuration/consts.hpp"
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

int x_movement = 1;
int y_movement = 1;

void simulate_ball(Ball* ball, Pad* pad) {
  // Hardcoded for now

  // Checking for collisions with pad/walls
  // Walls
  if (ball->geo.y + ball->geo.radius >= SCREEN_HEIGHT) y_movement *= -1;
  if (ball->geo.y - ball->geo.radius <= 0)             y_movement *= -1;

  if (ball->geo.x + ball->geo.radius >= SCREEN_WIDTH)  x_movement *= -1;
  if (ball->geo.x - ball->geo.radius <= 0)             x_movement *= -1;

  // Pad
  // bool x_might_intersect = false;
  // bool y_might_intersect = false;
  // if ((ball->geo.x + ball->geo.radius) > (pad->geo.x - pad->geo.size_x) || (ball->geo.x - ball->geo.radius) < (pad->geo.x + pad->geo.size_x)) printf("INFO: x might intersect!\n");
  // if ((false) > (false) || (false) < (false)) printf("INFO: y might intersect!\n");

  ball->geo.x += x_movement * BALL_SPEED;
  ball->geo.y += y_movement * BALL_SPEED;
}

