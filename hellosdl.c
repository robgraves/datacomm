#include <SDL2/SDL.h>
#include <stdio.h>

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

int main(int argc, char **argv)
{
	SDL_Window  *window   = NULL;
	SDL_Surface *surface  = NULL;

    SDL_Rect        box;

    box.x               = 50;
    box.y               = 50;
    box.w               = 540;
    box.h               = 380;

	SCREEN_WIDTH          = 640;
	SCREEN_HEIGHT         = 480;

	// Initialize SDL ( https://wiki.libsdl.org/SDL_Init )
	//
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "SDL could not initialize!");
		fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		// Create window
		window = SDL_CreateWindow("SDL_Tutorial",
								  0, 
								  0,
								  SCREEN_WIDTH,
								  SCREEN_HEIGHT,
								  SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			fprintf(stderr, "Window could not be created! ");
			fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			// Get window surface
			surface = SDL_GetWindowSurface(window);

			// Fill the surface the BEST color ever
			SDL_FillRect(surface,
			             NULL,
						 SDL_MapRGB(surface -> format, 0x63, 0xD2, 0x95));

            SDL_FillRect(surface,
                        &box,
                        SDL_MapRGB(surface -> format, 0x11, 0x22, 0xEE));

			// Update/paint the surface
			SDL_UpdateWindowSurface(window);

			// Wait 2 seconds
			SDL_Delay(2000);

			// Destroy window
			SDL_DestroyWindow(window);
		}
		
		SDL_Quit();
	}

	return(0);
}
