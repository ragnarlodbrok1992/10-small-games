#include "pad.hpp"

#include <stdio.h>

void init_pad(Pad* pad, int x, int y, int size_x, int size_y, Color color) {
  pad->geo.x = x;
  pad->geo.y = y;
  pad->geo.size_x = size_x;
  pad->geo.size_y = size_y;

  pad->render_info.color.r = color.r;
  pad->render_info.color.g = color.g;
  pad->render_info.color.b = color.b;
  pad->render_info.color.a = color.a;
}

void render_pad(SDL_Renderer* renderer, Pad* pad) {
  // printf("INFO: rendering pad -> %p\n", pad);
  // printf("INFO: with renderer -> %p\n", renderer);
  
  SDL_SetRenderDrawColor(renderer,
      pad->render_info.color.r,
      pad->render_info.color.g,
      pad->render_info.color.b,
      pad->render_info.color.a
  );

  SDL_Rect rect;
  rect.x = pad->geo.x;
  rect.y = pad->geo.y;
  rect.w = pad->geo.size_x;
  rect.h = pad->geo.size_y;

  SDL_RenderFillRect(renderer, &rect);

}
