#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    SDL_Joystick **pad;
    SDL_Event      e;

    int            JOYSTICK_DEAD_ZONE  = 1;
    int            x                   = 0;
    int            num_joysticks       = 0;
    int            quit                = 0;

    if (SDL_Init(SDL_INIT_JOYSTICK)   <  0)                  // bring only joystick functionality online
    {
        fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    num_joysticks                      = SDL_NumJoysticks(); // grab the number of connected joysticks
    if (num_joysticks                 <  1)
    {
        fprintf(stderr, "Warning: No joysticks connected!\n");
    }
    else
    {
        fprintf(stdout, "%d joysticks detected\n", num_joysticks);
        pad                            = (SDL_Joystick **)malloc(sizeof(SDL_Joystick *) * num_joysticks);
        for (x = 0; x < num_joysticks; x++)
        {
            *(pad+x)                   = SDL_JoystickOpen(x);
            if (*(pad+x)              == NULL)
            {
                fprintf(stderr, "Warning: Unable to open game controller %d!\n", x);
                fprintf(stderr, "SDL Error: %s\n", SDL_GetError());
            }
        }
    }

    while (quit                       == 0)                  // main (game) loop
    {
        while (SDL_PollEvent(&e)      != 0)
        {
            if (e.type                == SDL_QUIT)           // user clicks the 'X' on the window
            {
                quit                   = 1;
                break;
            }
            else if (e.type           == SDL_JOYAXISMOTION)  // joystick-related event
            {
                fprintf(stdout, "joystick #: %d (%d of %d)\n", e.jaxis.which, e.jaxis.which+1, num_joysticks);
                fprintf(stdout, "      axis: %d ",          e.jaxis.axis);
                if (e.jaxis.axis      >  0)
                    fprintf(stdout, "x-axis (up-down)\n");
                else
                    fprintf(stdout, "num_joysticks-axis (left-right)\n");
                fprintf(stdout, "     value: %d\n\n",       e.jaxis.value);
            }
			else if (e.type           == SDL_JOYBUTTONDOWN)
			{
				fprintf(stdout, "joystick #: %d\n", e.jbutton.which);
				fprintf(stdout, "  button #: %d\n", e.jbutton.button);
				fprintf(stdout, "\n");
			}
        }
    }

    for (x = 0; x < num_joysticks; x++)                      // close each open joystick
    {
        SDL_JoystickClose(*(pad+x));
        *(pad+x)                       = NULL;
    }

    // at the end
    SDL_Quit();

    return(0);
}
