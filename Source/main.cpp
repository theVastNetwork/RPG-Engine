#include <iostream>
#include <SDL2/SDL.h>

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("RPG Version 1.0 Alpha", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    
    SDL_Event event;
    bool isRunning = true;
    
    while (isRunning)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }
        }
        SDL_UpdateWindowSurface(window);
        SDL_RenderClear(renderer);
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    system("exit");
    return 0;
}
