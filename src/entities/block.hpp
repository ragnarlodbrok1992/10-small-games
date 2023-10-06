#ifndef _H_BLOCK
#define _H_BLOCK

#include "geometry.hpp"
#include "../rendering/renderinfo.hpp"
#include "../configuration/consts.hpp"

constexpr int BLOCKS_X = 20;
constexpr int BLOCKS_Y = 5;
constexpr int BLOCK_SPACE_BETWEEN = 10;
constexpr int BLOCK_X_SIZE = (int) (SCREEN_WIDTH / BLOCKS_X) - (2 * BLOCK_SPACE_BETWEEN);
constexpr int BLOCK_Y_SIZE = (int) ((SCREEN_HEIGHT / 3) / BLOCKS_Y) - BLOCK_SPACE_BETWEEN;
constexpr int BLOCK_INIT_X = (int) 10;
constexpr int BLOCK_INIT_Y = (int) 10;


typedef struct {
  RectGeometry geo;
  RenderInfo render_info;
} Block;

// Color of blocks depends on its position for now
Block init_block(int x, int y);


#endif /* _H_BLOCK */

