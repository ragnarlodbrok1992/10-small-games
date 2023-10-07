#include "block.hpp"

#include <stdio.h>

Block init_block(int x, int y) {
  Block block;

  block.geo.x = BLOCK_INIT_X + (BLOCK_X_SIZE + BLOCK_SPACE_BETWEEN) * x;
  block.geo.y = BLOCK_INIT_Y + (BLOCK_Y_SIZE + BLOCK_SPACE_BETWEEN) * y;
  block.geo.size_x = BLOCK_X_SIZE;
  block.geo.size_y = BLOCK_Y_SIZE;

#if 0
  float x_  = x / (float) (BLOCKS_X * BLOCKS_Y);
  float y_  = y / (float) (BLOCKS_X * BLOCKS_Y);
  float xy_ = (x + y) / (float) (BLOCKS_X * BLOCKS_Y);
  
  printf("INFO: x_  %f\n", x_);
  printf("INFO: y_  %f\n", y_);
  printf("INFO: xy_ %f\n", xy_);
#endif

  // @TODO fix this shit
  block.render_info.color.r = (int) ((x / (float) (BLOCKS_X * BLOCKS_Y)) * 0xFF);
  block.render_info.color.g = (int) ((y / (float) (BLOCKS_X * BLOCKS_Y)) * 0xFF);
  block.render_info.color.b = (int) (((x + y) / (float) (BLOCKS_X * BLOCKS_Y)) * 0xFF);
  block.render_info.color.a = 0xFF;

#if 0
  printf("INFO: block.render_info.color.r -> %x\n", block.render_info.color.r);
  printf("INFO: block.render_info.color.g -> %x\n", block.render_info.color.g);
  printf("INFO: block.render_info.color.b -> %x\n", block.render_info.color.b);
  printf("INFO: block.render_info.color.a -> %x\n", block.render_info.color.a);
  printf("\n");
#endif


  return block;
}

void render_blocks(SDL_Renderer* renderer, Block* blocks, size_t size) {
  for (size_t x = 0; x < size; x++) {
    // printf("INFO: rendering block %p\n", &blocks[x]);

    SDL_SetRenderDrawColor(renderer,
        blocks[x].render_info.color.r,
        blocks[x].render_info.color.g,
        blocks[x].render_info.color.b,
        blocks[x].render_info.color.a
    );

    SDL_Rect rect;
    rect.x = blocks[x].geo.x;
    rect.y = blocks[x].geo.y;
    rect.w = blocks[x].geo.size_x;
    rect.h = blocks[x].geo.size_y;

    SDL_RenderFillRect(renderer, &rect);
  }
}
