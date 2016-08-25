#include <SDL2/SDL.h>
#include <stdio.h>

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

int main (int argc, char **argv)
{
    SDL_Window  *window     = NULL;
    SDL_Surface *surface    = NULL;
    SDL_Surface *image      = NULL;
    SDL_Surface *small      = NULL;

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
            
            image       = SDL_LoadBMP("imagefun.bmp");
            if (image   == NULL)
            {
                fprintf(stderr, "Unable to load image %s! ", "imagefun.bmp");
                fprintf(stderr, "SDL Error: %s\n", SDL_GetError());
                exit(1);
            }

            small       = SDL_LoadBMP("small.bmp");
            if (small   == NULL)
            {
                fprintf(stderr, "Unable to load image %s! ", "imagefun.bmp");
                fprintf(stderr, "SDL Error: %s\n", SDL_GetError());
                exit(1);
            }

            SDL_BlitSurface(image, NULL, surface, NULL);

            box.x           = 730;
            box.y           = 514;
            box.w           = 70;
            box.h           = 86;

            SDL_BlitSurface(small, NULL, surface, &box);

            SDL_UpdateWindowSurface(window);

            SDL_Delay(2000);

            SDL_DestroyWindow(window);

            SDL_Quit();
        }
    }

    return(0);
}
