#include <stdio.h>
#include <stdbool.h>

// SDL Deps.
#include <SDL.h>
#include <SDL_ttf.h>

int main(int argc, char* argv[]) {
  bool inited = true;
  if(SDL_Init(SDL_INIT_VIDEO) != 0) { printf("%s %s\n", "SDL INIT ERROR!", SDL_GetError()); inited = false; }
  if(TTF_Init() != 0) { printf("%s %s\n", "SDL TTF ERROR!", TTF_GetError()); inited = false; }

  if(!inited) {
    printf("%s\n", "Something fucked up badly, see the error above.");
    return 1;
  }
  
  // Setup window
  SDL_Window* window;
  SDL_Renderer* render;

  SDL_CreateWindowAndRenderer(640, 360, SDL_WINDOW_SHOWN, &window, &render);

  // Game loop
  bool running = true;

  TTF_Font* Sans = TTF_OpenFont("/usr/share/fonts/JetBrainsMono/JetBrainsMonoNLNerdFontMono-Bold.ttf", 24);

  SDL_Color White = {0, 0, 0};

  SDL_Surface* surfaceMessage =
      TTF_RenderText_Solid(Sans, "Hello, world!", White); 

  SDL_Texture* Message = SDL_CreateTextureFromSurface(render, surfaceMessage);

  SDL_Rect Message_rect; //create a rect
  Message_rect.x = 0;  //controls the rect's x coordinate 
  Message_rect.y = 0; // controls the rect's y coordinte
  Message_rect.w = surfaceMessage->w; // controls the width of the rect
  Message_rect.h = surfaceMessage->h; // controls the height of the rect


  while(running) {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT) running = false;
    }
    
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    SDL_RenderClear(render);

    SDL_RenderCopy(render, Message, NULL, &Message_rect);

    SDL_RenderPresent(render);
  }

  // Clean up
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(render);
  return 0;
}
