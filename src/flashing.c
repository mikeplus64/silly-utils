#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <math.h>

const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 600;
const char* WINDOW_TITLE = "PANIC!";

int main(int argc, char **argv)
{
    int HWH = WINDOW_HEIGHT/2;
    int HWW = WINDOW_WIDTH/2;
    int offs = 0;
    int incr = 1;
    int Trippin = 1;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface* screen = SDL_SetVideoMode( WINDOW_WIDTH, WINDOW_HEIGHT, 0, 
            SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
    SDL_WM_SetCaption( WINDOW_TITLE, 0 );
    SDL_Event event;
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

    while (Trippin == 1)
    {
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    Trippin=0;
                    break;
                default:
                    break;
            }
        }
        int x, y, r, g, b, a=255, xxory;

        if(offs <= 1)
            incr = 1;
        else if(offs == 5000)
            incr = -1;

        offs += incr;
        for(y = -(HWH); y < HWH; y ++)
        {
            for(x = -(HWW); x < HWW; x ++)
            {
                xxory = (x ^ y) ^ offs;
                r = offs - x + y | xxory;
                g = offs + x - y & xxory;
                b = offs + x + y ^ xxory;
                pixelRGBA(screen, x+HWW, y+HWH, r, g, b, a);
            }
        }
        SDL_Flip(screen);
    }
    SDL_Quit();
    return 0;
}
