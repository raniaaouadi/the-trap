#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "score.h"

void main(int argc, char **argv)
{
    SDL_Surface *ecran = NULL;
    SDL_Event event;
    int continuer=1;
    score s;
    int k=0;

    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE |SDL_DOUBLEBUF);
    SDL_WM_SetCaption(" teste 1 dans affichage objet  ", NULL);
  //  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
      TTF_Init();    
      
/********************************************************************************************************************/
     s=intialiser_score(s);
     
    while(continuer)
    {   
       SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        s=gestion_score(s,ecran); 
        /********************************************************************************************/
       afficher_score(s,ecran);
       SDL_PollEvent(&event); 
       switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;
            
        }      
    }

free_score(s,ecran);
SDL_Quit();

}
