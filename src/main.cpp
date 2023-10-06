// Global includes - frameworks and such
#include <SDL2/SDL.h>

// Compiler includes
#include <stdio.h>
#include <stdint.h>

// Local includes - engine and game stuff
#include "entities/pad.hpp"
#include "configuration/consts.hpp"

// Framework variables
SDL_Window*   WINDOW = NULL;
// SDL_Surface*  SURFACE = NULL;
SDL_Renderer* RENDERER = NULL;

// Engine variables
bool ENGINE_RUNNING = true;

// Entities
Pad   PAD;
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

  // Initialize entities
  init_pad(&PAD, PAD_X, PAD_Y, PAD_X_SIZE, PAD_Y_SIZE, PAD_COLOR);

  while (ENGINE_RUNNING) {
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
          }
          break;
      }
    }

    // Render
    // Clear screen
    SDL_SetRenderDrawColor(RENDERER, 0xe6, 0x49, 0x27, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(RENDERER);

    // Render pad
    render_pad(RENDERER, &PAD);

    // Switch buffer - backbuffer to front
    SDL_RenderPresent(RENDERER);
  }

  // Destroying stuff here
  SDL_DestroyWindow(WINDOW);

  SDL_Quit();

  printf("Last message - goodbye.\n");
  return 0;
}

