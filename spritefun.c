#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

int main(int argc, char **argv)
{
	SDL_Window  *window   = NULL;
	SDL_Surface *surface  = NULL;
	SDL_Surface *image    = NULL;

	SDL_Rect     box;
	SDL_Rect     sprite;

	sprite.x              = 0;
	sprite.y              = 0;
	sprite.w              = 48;
	sprite.h              = 64;

	int          x        = 0;
	int          y        = 0;

	int quit              = 0;
	SDL_Event    e;

	SCREEN_WIDTH          = atoi(argv[1]);
	SCREEN_HEIGHT         = atoi(argv[2]);

	box.x                 = (SCREEN_WIDTH  / 2) - 35;
	box.y                 = (SCREEN_HEIGHT / 2) - 43;
	box.w                 = 70;
	box.h                 = 86;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}

	window                = SDL_CreateWindow("Sparkles! Sparkles!!",
											 SDL_WINDOWPOS_UNDEFINED,
											 SDL_WINDOWPOS_UNDEFINED,
											 SCREEN_WIDTH,
											 SCREEN_HEIGHT,
											 SDL_WINDOW_SHOWN);

	if (window           == NULL)
	{
		fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}

	surface               = SDL_GetWindowSurface(window);
	image                 = SDL_LoadBMP("mudkip.bmp");

	SDL_FillRect(surface,
				 NULL,
				 SDL_MapRGB(surface -> format, 0x00, 0x00, 0x00));

	SDL_BlitSurface(image, &sprite, surface, &box);
	SDL_UpdateWindowSurface(window);

	// stuff
	while (quit == 0)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			// user clicks the 'X' on the window
			if (e.type   == SDL_QUIT)
			{
				quit      = 1;
				break;
			}
			if (e.type   == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
					case SDLK_UP:
						box.y     = box.y - 10;
						sprite.y  = 0;
						break;

					case SDLK_DOWN:
						box.y     = box.y + 10;
						sprite.y  = 128;
						break;

					case SDLK_LEFT:
						box.x     = box.x - 10;
						sprite.y  = 192;
						break;

					case SDLK_RIGHT:
						box.x  = box.x + 10;
						sprite.y  = 64;
						break;

					case SDLK_SPACE:
						box.x  = (SCREEN_WIDTH  / 2) - 35;
						box.y  = (SCREEN_HEIGHT / 2) - 43;
						break;

					case SDLK_ESCAPE:
						quit   = 1;
						break;
				}
				SDL_FillRect(surface,
							 NULL,
							 SDL_MapRGB(surface -> format, 0x00, 0x00, 0x00));

				SDL_BlitSurface(image, &sprite, surface, &box);
				SDL_UpdateWindowSurface(window);
			}
		}
	}

	// at the end
	SDL_DestroyWindow(window);
	SDL_Quit();

	return(0);
}
