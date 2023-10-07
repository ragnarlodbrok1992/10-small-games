// Global includes - frameworks and such
#include <SDL2/SDL.h>

// Compiler includes
#include <stdio.h>
#include <stdint.h>

// Local includes - engine and game stuff
#include "entities/pad.hpp"
#include "entities/ball.hpp"
#include "entities/block.hpp"
#include "configuration/consts.hpp"

// Framework variables
SDL_Window*   WINDOW = NULL;
// SDL_Surface*  SURFACE = NULL;
SDL_Renderer* RENDERER = NULL;

// Engine variables
bool ENGINE_RUNNING = true;

// Entities
Pad   PAD;
PadControls PAD_CONTROLS;
Ball  BALL;
constexpr int NUM_OF_BLOCKS = BLOCKS_X * BLOCKS_Y;
Block BLOCKS[NUM_OF_BLOCKS];
Color PAD_COLOR = {.r = 0x27, .g = 0xe6, .b = 0xd5, .a = 0xFF};

int main() {
  printf("Small engine for 10 games.\n");

  if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  } else { printf("Initialization successful!\n"); }

  WINDOW = SDL_CreateWindow("Breakout - for itch.io by Ragnar.", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  // SURFACE = SDL_GetWindowSurface(WINDOW); // @TODO check for errors

  if (WINDOW == NULL) {
    printf("Window couldn't be created! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  uint32_t RenderFlags = SDL_RENDERER_ACCELERATED;
  // uint32_t RenderFlags = SDL_RENDERER_SOFTWARE;
  RENDERER = SDL_CreateRenderer(WINDOW, -1, RenderFlags); // @INFO: Either use surface or renderer, those two cannot go together
  if (RENDERER == NULL) {
    printf("SDL could not initialize renderer! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // Initialize local entities
  PAD_CONTROLS.controls = 0;

  for (int x = 0; x < NUM_OF_BLOCKS; x++) {
    int local_x = x % BLOCKS_X;
    int local_y = (int) x / BLOCKS_X;

    printf("INFO: initializing block nr %d\n", x);
    printf("INFO:   local_x %d\n", local_x);
    printf("INFO:   local_y %d\n", local_y);
    printf("\n");
  }

  // Initialize entities
  init_pad(&PAD, PAD_X, PAD_Y, PAD_X_SIZE, PAD_Y_SIZE, PAD_COLOR);
  init_ball(&BALL, BALL_X, BALL_Y, BALL_RADIUS);

  int PREVIOUS_FRAME_TIME = 0;

  while (ENGINE_RUNNING) {
    // Zero control variables
    // PAD_CONTROLS.controls = 0;

    SDL_Event e;

    // Events
    while (SDL_PollEvent(&e) != 0) {
      switch (e.type) {
        case SDL_QUIT:
          ENGINE_RUNNING = false;
          break;

        case SDL_KEYDOWN:
          // Key pressed
          switch (e.key.keysym.sym) {
            case SDLK_q:
              ENGINE_RUNNING = false;
              break;

          // Pad controls
            case SDLK_LEFT:
              // PAD_CONTROLS.controls += 0x10; // @TODO do not do stuff like that - just set the bit
              PAD_CONTROLS.controls |= 1 << 2; // Defined in pad.hpp
              break;
            case SDLK_RIGHT:
              // PAD_CONTROLS.controls += 0x01; // @TODO same as above
              PAD_CONTROLS.controls |= 1 << 1; // Defined in pad.hpp
              break;
          }
          break;

        case SDL_KEYUP:
          switch (e.key.keysym.sym) {
            // Pad controls
            case SDLK_LEFT:
              PAD_CONTROLS.controls &= ~(1 << 2);
              break;
            case SDLK_RIGHT:
              PAD_CONTROLS.controls &= ~(1 << 1);
              break;
          }
          break;
      }
    }

    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - PREVIOUS_FRAME_TIME);

    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
      SDL_Delay(time_to_wait);
    }

    PREVIOUS_FRAME_TIME = SDL_GetTicks();

    // Simulate state @TODO we need to have delta time for this and this requires us to use floats????
    simulate_pad(&PAD, &PAD_CONTROLS);
    simulate_ball(&BALL, &PAD);

    // Render
    // Clear screen
    SDL_SetRenderDrawColor(RENDERER, 0xe6, 0x49, 0x27, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(RENDERER);

    // Render pad
    render_pad(RENDERER, &PAD);

    // Render ball
    render_ball(RENDERER, &BALL);

    // Switch buffer - backbuffer to front
    SDL_RenderPresent(RENDERER);
  }

  // Destroying stuff here
  SDL_DestroyWindow(WINDOW);

  SDL_Quit();

  printf("Last message - goodbye.\n");
  return 0;
}

