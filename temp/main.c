#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "temp.h"

void main(int argc, char **argv)
{
    SDL_Surface *ecran = NULL;
    SDL_Event event;
    int continuer=1,diff=1,pause_time_disc=0,pause_time_pause=0;
    tempss temp;

    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(900, 600, 32, SDL_HWSURFACE |SDL_DOUBLEBUF);
    SDL_WM_SetCaption(" teste 1 dans affichage objet  ", NULL);
    TTF_Init();
    temp=inisaliser_temp_compteur(temp,diff);
    while(continuer)
    {   
    
     temp=gestion_temps_compteur(pause_time_disc,pause_time_pause,temp,ecran);
     printf("h=%d m=%d s=%d \n",temp.heur1,temp.minute1,temp.seconde1);
       SDL_PollEvent(&event); 
       switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;
            
        }      
    
    }
free_temps(temp);
SDL_Quit();
}
