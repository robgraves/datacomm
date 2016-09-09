#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

int main(int argc, char **argv)
{
    SDL_Window    *window     = NULL;
    SDL_Surface   *surface    = NULL;
    SDL_Surface   *image      = NULL;
    SDL_Surface   *block      = NULL;
    SDL_Joystick **pad        = NULL;
    SDL_Event      e;

    SDL_Rect       box;
    SDL_Rect       sprite;
    SDL_Rect       blockbox;
    SDL_Rect       blockpos;

    int            DEAD_ZONE  = 1;
    int            x          = 0;
    int            num_pads   = 0;
    int            frame      = 0;
    int quit                  = 0;
	int            go         = 5;

    Uint32         rmask;
    Uint32         gmask;
    Uint32         bmask;
    Uint32         amask;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask                     = 0xff000000;
    gmask                     = 0x00ff0000;
    bmask                     = 0x0000ff00;
    amask                     = 0x000000ff;
#else
    rmask                     = 0x000000ff;
    gmask                     = 0x0000ff00;
    bmask                     = 0x00ff0000;
    amask                     = 0xff000000;
#endif

    sprite.x                  = 0;
    sprite.y                  = 0;
    sprite.w                  = 48;
    sprite.h                  = 64;


    if (argc                 >= 3)
    {
        SCREEN_WIDTH          = atoi(argv[1]);
        SCREEN_HEIGHT         = atoi(argv[2]);
    }
    else
    {
        SCREEN_WIDTH          = 800;
        SCREEN_HEIGHT         = 600;
    }

    box.x                     = (SCREEN_WIDTH  / 2) - 35;
    box.y                     = (SCREEN_HEIGHT / 2) - 43;
    box.w                     = 70;
    box.h                     = 86;

    blockbox.x                = 0;
    blockbox.y                = 0;
    blockbox.w                = 40;
    blockbox.h                = 40;

    if (SDL_Init(SDL_INIT_EVERYTHING) <  0)
    {
        fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    num_pads                  = SDL_NumJoysticks();
    if (num_pads             <  1)
    {
        fprintf(stderr, "Warning: No joysticks connected!\n");
    }
    else
    {
        fprintf(stdout, "%d joysticks detected\n", num_pads);
        pad                   = (SDL_Joystick **) malloc(sizeof(SDL_Joystick *) * num_pads);
        for (x = 0; x < num_pads; x++)
        {
            *(pad+x)          = SDL_JoystickOpen(x);
            if (*(pad+x)     == NULL)
            {
                fprintf(stderr, "Warning: Unable to open game controller %d!\n", x);
                fprintf(stderr, "SDL Error: %s\n", SDL_GetError());
            }
        }
    }


    window                    = SDL_CreateWindow("Sparkles! Sparkles!!",
                                                 SDL_WINDOWPOS_UNDEFINED,
                                                 SDL_WINDOWPOS_UNDEFINED,
                                                 SCREEN_WIDTH,
                                                 SCREEN_HEIGHT,
                                                 SDL_WINDOW_SHOWN);


    if (window               == NULL)
    {
        fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    surface                   = SDL_GetWindowSurface(window);
    image                     = SDL_LoadBMP("mudkip.bmp");


    block                     = SDL_CreateRGBSurface(0,
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
    blockpos.x                = 0;
    blockpos.y                = 0;
    for (x = 0; x <= SCREEN_WIDTH; x+=blockpos.w)
    {
        blockpos.y            = 0;
        SDL_BlitSurface(block, NULL, surface, &blockpos);
        blockpos.y            = SCREEN_HEIGHT - blockbox.h;
        SDL_BlitSurface(block, NULL, surface, &blockpos);
        blockpos.x            = x;
    }

    blockpos.x                = 0;
    blockpos.y                = 0;
    for (x = 0; x <= SCREEN_HEIGHT; x+=blockpos.h)
    {
        blockpos.x            = 0;
        SDL_BlitSurface(block, NULL, surface, &blockpos);
        blockpos.x            = SCREEN_WIDTH - blockbox.w;
        SDL_BlitSurface(block, NULL, surface, &blockpos);
        blockpos.y            = x;
    }
    SDL_UpdateWindowSurface(window);

    // stuff

        while (quit          == 0)
        {
            SDL_PollEvent(&e);

			// button integration
			if (e.type       == SDL_JOYBUTTONDOWN)
			{
				if (e.jbutton.button == 1)
				{
					go        = 10;
				}
			}
			else if (e.type  == SDL_JOYBUTTONUP)
			{
				go = 5;
			}

            // user clicks the 'X' on the window
            if (e.type       == SDL_QUIT)
            {
                quit          = 1;
                break;
            }
            else if (e.type  == SDL_JOYAXISMOTION && e.jaxis.value != 0)
            {
                if (e.jaxis.which == 0) // motion on controller 0
                {
                    if (e.jaxis.axis == 0) // on the X axis
                    {
                        fprintf(stdout, "%d\t%d\n", e.jaxis.axis, e.jaxis.value);
                        if (e.jaxis.value < 0) // left
                        {
                            box.x = box.x - go;
                            sprite.y = 192;
                            frame = frame + 1;                            
                        }
                        else if (e.jaxis.value > 0) //right
                        {
                            box.x = box.x + go;
                            sprite.y = 64;
                            frame = frame + 1;
                        }
                    }
                    else if (e.jaxis.axis == 1) // on the Y axis
                    {
                        fprintf(stdout, "%d\t%d\n", e.jaxis.axis, e.jaxis.value);
                        if (e.jaxis.value < 0) // up
                        {
                            box.y = box.y - go;
                            sprite.y = 0;
                            frame = frame + 1;
                        }
                        else if (e.jaxis.value > 0) //down
                        {
                            box.y = box.y + go;
                            sprite.y = 128;
                            frame = frame + 1;
                        }
                        
                    }
                }
            }
            else if (e.type   == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                    case SDLK_UP:
                        box.y     = box.y - go;
                        sprite.y  = 0;
                        frame     = frame + 1;
                        break;

                    case SDLK_DOWN:
                        box.y     = box.y + go;
                        sprite.y  = 128;
                        frame     = frame + 1;
                        break;

                    case SDLK_LEFT:
                        box.x     = box.x - go;
                        sprite.y  = 192;
                        frame     = frame + 1;
                        break;

                    case SDLK_RIGHT:
                        box.x  = box.x + go;
                        sprite.y  = 64;
                        frame     = frame + 1;
                        break;

                    case SDLK_SPACE:
                        box.x     = (SCREEN_WIDTH  / 2) - 35;
                        box.y     = (SCREEN_HEIGHT / 2) - 43;
                        frame     = frame + 1;
                        break;

                    case SDLK_ESCAPE:
                        quit = 1;
                        break;
                }
            }
            SDL_FillRect(surface,
                         NULL,
                         SDL_MapRGB(surface -> format, 0x00, 0x00, 0x00));


			if (box.x < blockpos.w)
				box.x = blockpos.w + 1;

			if (box.x + box.w > SCREEN_WIDTH - blockpos.w)
				box.x = SCREEN_WIDTH - blockpos.w - box.w;

			if (box.y < blockpos.h)
				box.y = blockpos.h + 1;

			if (box.y + box.h > SCREEN_HEIGHT - blockpos.h)
				box.y = SCREEN_HEIGHT - blockpos.h - box.h;

            frame                 = frame % 3;
            sprite.x              = frame * sprite.w;
            SDL_BlitSurface(image, &sprite, surface, &box);
            blockpos.x            = 0;
            blockpos.y            = 0;
            for (x = 0; x <= SCREEN_WIDTH; x+=blockpos.w)
            {
                blockpos.y        = 0;
                SDL_BlitSurface(block, NULL, surface, &blockpos);
                blockpos.y        = SCREEN_HEIGHT - blockbox.h;
                SDL_BlitSurface(block, NULL, surface, &blockpos);
                blockpos.x        = x;
            }

            blockpos.x            = 0;
            blockpos.y            = 0;
            for (x = 0; x <= SCREEN_HEIGHT; x+=blockpos.h)
            {
                blockpos.x        = 0;
                SDL_BlitSurface(block, NULL, surface, &blockpos);
                blockpos.x        = SCREEN_WIDTH - blockbox.w;
                SDL_BlitSurface(block, NULL, surface, &blockpos);
                blockpos.y        = x;
            }
            SDL_UpdateWindowSurface(window);
        }

    for (x = 0; x < num_pads; x++)
    {
        SDL_JoystickClose(*(pad+x));
        *(pad+x)                  = NULL;
    }

    // at the end
    SDL_DestroyWindow(window);
    SDL_Quit();

    return(0);
}
