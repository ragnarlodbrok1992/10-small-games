#ifndef _H_CONSTS
#define _H_CONSTS

#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

// Engine variables @TODO move those into lower in hierarchy so those can be seen by entities and other stuff
// Some of them cannot be here because of multiple definitions error
constexpr int SCREEN_WIDTH  = 1024;
constexpr int SCREEN_HEIGHT = 768;

#endif /* _H_CONSTS */

