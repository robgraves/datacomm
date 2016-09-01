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
	SDL_Surface *block    = NULL;

	SDL_Rect     box;
	SDL_Rect     sprite;
	SDL_Rect     blockbox;
	SDL_Rect     blockpos;

	Uint32       rmask;
	Uint32       gmask;
	Uint32       bmask;
	Uint32       amask;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
#else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
#endif

	sprite.x              = 0;
	sprite.y              = 0;
	sprite.w              = 48;
	sprite.h              = 64;

	int          x        = 0;
	int          y        = 0;

	int          frame    = 0;

	int quit              = 0;
	SDL_Event    e;

	SCREEN_WIDTH          = atoi(argv[1]);
	SCREEN_HEIGHT         = atoi(argv[2]);

	box.x                 = (SCREEN_WIDTH  / 2) - 35;
	box.y                 = (SCREEN_HEIGHT / 2) - 43;
	box.w                 = 70;
	box.h                 = 86;

	blockbox.x            = 0;
	blockbox.y            = 0;
	blockbox.w            = 40;
	blockbox.h            = 40;

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


	block                 = SDL_CreateRGBSurface(0,
												 blockbox.w,
												 blockbox.h,
												 24,
												 rmask,
												 gmask,
												 bmask,
												 amask);

	SDL_FillRect(surface,
				 NULL,
				 SDL_MapRGB(surface -> format, 0x00, 0x00, 0x00));

	SDL_FillRect(block,
				 NULL,
				 SDL_MapRGB(block   -> format, 0xFF, 0xFF, 0xFF));

	SDL_BlitSurface(image, &sprite, surface, &box);
	blockpos.x = 0;
	blockpos.y = 0;
	for (x = 0; x <= SCREEN_WIDTH; x+=blockpos.w)
	{
		blockpos.y  = 0;
		SDL_BlitSurface(block, NULL,    surface, &blockpos);
		blockpos.y  = SCREEN_HEIGHT - blockbox.h;
		SDL_BlitSurface(block, NULL,    surface, &blockpos);
		blockpos.x  = x;
	}

	blockpos.x = 0;
	blockpos.y = 0;
	for (y = 0; y <= SCREEN_HEIGHT; y+=blockpos.h)
	{
		blockpos.x  = 0;
		SDL_BlitSurface(block, NULL,    surface, &blockpos);
		blockpos.x  = SCREEN_WIDTH - blockbox.w;
		SDL_BlitSurface(block, NULL,    surface, &blockpos);
		blockpos.y  = y;
	}
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
						frame     = frame + 1;
						break;

					case SDLK_DOWN:
						box.y     = box.y + 10;
						sprite.y  = 128;
						frame     = frame + 1;
						break;

					case SDLK_LEFT:
						box.x     = box.x - 10;
						sprite.y  = 192;
						frame     = frame + 1;
						break;

					case SDLK_RIGHT:
						box.x  = box.x + 10;
						sprite.y  = 64;
						frame     = frame + 1;
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

				frame             = frame % 3;
				sprite.x          = frame * sprite.w;
				SDL_BlitSurface(image, &sprite, surface, &box);
				blockpos.x = 0;
				blockpos.y = 0;
				for (x = 0; x <= SCREEN_WIDTH; x+=blockpos.w)
				{
					blockpos.y  = 0;
					SDL_BlitSurface(block, NULL,    surface, &blockpos);
					blockpos.y  = SCREEN_HEIGHT - blockbox.h;
					SDL_BlitSurface(block, NULL,    surface, &blockpos);
					blockpos.x  = x;
				}

				blockpos.x = 0;
				blockpos.y = 0;
				for (y = 0; y <= SCREEN_HEIGHT; y+=blockpos.h)
				{
					blockpos.x  = 0;
					SDL_BlitSurface(block, NULL,    surface, &blockpos);
					blockpos.x  = SCREEN_WIDTH - blockbox.w;
					SDL_BlitSurface(block, NULL,    surface, &blockpos);
					blockpos.y  = y;
				}
				SDL_UpdateWindowSurface(window);
			}
		}
	}

	// at the end
	SDL_DestroyWindow(window);
	SDL_Quit();

	return(0);
}
