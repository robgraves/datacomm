#include <SDL2/SDL.h>
#include <stdio.h>

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

int main (int argc, char **argv)
{
    SDL_Window  *window     = NULL;
    SDL_Surface *surface    = NULL;

    SDL_Rect    box;

    SCREEN_WIDTH    = 800;
    SCREEN_HEIGHT   = 600;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        fprintf(stderr, "SDL could not initialize!");
        fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        window  = SDL_CreateWindow("Image Fun",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);
        if (window      == NULL)
        {
            fprintf(stderr, "Window could not be created! ");
            fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            surface     = SDL_GetWindowSurface(window);
        }
    }

    return(0);
}
