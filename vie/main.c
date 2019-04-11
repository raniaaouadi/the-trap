#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "vie.h"

void main(int argc, char **argv)
{
    SDL_Surface *ecran = NULL;
    SDL_Event event;
    int continuer=1;
    vie v;

    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(900, 600, 32, SDL_HWSURFACE |SDL_DOUBLEBUF);
    SDL_WM_SetCaption(" teste 1 dans affichage objet  ", NULL);
    //SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    //SDL_Flip(ecran);

    //  TTF_Init();    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_Flip(ecran);    
/********************************************************************************************************************/

     v=init_vie(v) ;
    // displayvie(v,ecran) ; 
    int test=0,k=0;
    while(continuer)
    {   
      //  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        //SDL_FreeSurface(v.image[v.val]);
        v=updatevie(v,test,ecran); 
        displayvie(v,ecran) ;
       //SDL_FreeSurface(v.image[v.val]);
       SDL_Delay(10000);
       k++;
       printf(" k==== %d \n",k);
       if(k>=2){test=1;} 
        /********************************************************************************************/
       SDL_PollEvent(&event); 
       switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;
            
        }      
    //if(v.val!=0) {SDL_FreeSurface(v.image[v.val--]);}
    
    }
vie_freevie(v) ;  
SDL_Quit();
}
