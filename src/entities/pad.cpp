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

