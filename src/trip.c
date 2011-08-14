#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 600;
const char* WINDOW_TITLE = "TRIP!";

int main(int argc, char **argv)
{
    int HWW = WINDOW_WIDTH/2;
    int HWH = WINDOW_HEIGHT/2;
    int offs = 0;
    int incr = 1;
    int Trippin = 1;
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        printf("you are a horrible person and I hate you\n");
        return 1;
    }
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface* screen = SDL_SetVideoMode( WINDOW_WIDTH, WINDOW_HEIGHT, 0, 
            SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN );
    SDL_WM_SetCaption( WINDOW_TITLE, 0 );
    SDL_Event event;
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    SDL_ShowCursor(0);
    
    while(Trippin==1)
    {
        if(SDL_PollEvent(&event))
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
        int x, y;
        int r=255, o, a;

        if(offs <= 1)
            incr = 1;
        else if(offs == 2048)
            incr = -1;

        offs += incr;
        for(y = 0; y < WINDOW_HEIGHT; y ++)
        {
            for(x = 0; x < WINDOW_WIDTH; x ++)
            {
                a = (pow(x-HWW,2)/(pow(y-HWH,2)))+offs;
                o = sqrt(a);
                r = (a * o) & (a ^ o + 1) | (a / (o+1));
                pixelRGBA(screen, x, y, r, r, r, o);
            }
        }
        SDL_Flip(screen);
    }
    SDL_Quit();
    return 0;
    //merry tripping!
}
