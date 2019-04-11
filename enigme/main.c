#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigme1.h"

int main(int argc, char *argv[])
{
    image quiz1,quiz2,quiz3,quiz4,correct1,correct2,correct3,mabrouk;
    SDL_Surface *ecran=NULL,*fixation=NULL,*parole=NULL,*logo_[1000],*click_here[1000],*bad_signal[1000],*curseur=NULL;
    SDL_Rect poscurseur;
    char logo[500],clickhere[500],badsignal[500];
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    SDL_Event event;
    ecran = SDL_SetVideoMode(900, 600, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    int continuer=1,j,i,clic=0,annimation=0,nombreclickhere=0,enigmeDone=1,done=1,entrer,terminer1=0,terminer2=0,terminer3=0,win=-1;
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1){printf("%s", Mix_GetError());}
    Music_annimation();
    annimation_enigme1(ecran);
    click_here_pls(ecran);
    quiz1=init_image("img/quiz1.png",0,0);
    correct1=init_image("img/correct1.jpg",0,0);
    quiz2=init_image("img/quiz2.png",0,0);
    correct2=init_image("img/correct2.png",0,0);
    quiz3=init_image("img/quiz3.png",0,0);
    correct3=init_image("img/correct3.png",0,0);
    mabrouk=init_image("img/mabrouk.png",0,0);
    curseur=IMG_Load("img/curseur2.png");
    poscurseur.x=0;
    poscurseur.y=0;
    while(continuer)
    {SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONDOWN:
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            { 
              if(clic!=2)
               {  if ( event.button.x >525 && event.button.y >475 && event.button.x < 543 && event.button.y <496)
                  {
                    printf("ok \n");
                    clic=1;
               }  }
            }
        }break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)// win teta9ra l click
            {
             case SDLK_RETURN:
             {
            if(enigmeDone==1)
            { if(poscurseur.y==435&&poscurseur.x==770)
              {
               sound_correct();affichage(ecran,correct1);SDL_Flip(ecran);SDL_Delay(3900);
               printf("win Enigme 1 \n");enigmeDone=2;done=1;terminer1=1;
              } 
              else{sound_wrong();printf("False Enigme 1\n");}
            }
            if(enigmeDone==2&&done==2)
            { if(poscurseur.y==510&&poscurseur.x==590)
              {
              sound_correct();affichage(ecran,correct2);SDL_Flip(ecran);SDL_Delay(3900);
              printf("win Enigme 2 \n");enigmeDone=3;done=2;terminer2=1;
              } 
              else{sound_wrong();printf("False Enigme 2\n");}
            }
            if(enigmeDone==3&&done==3)
            { if(poscurseur.y==510&&poscurseur.x==590)
              {
               sound_correct();affichage(ecran,correct3);SDL_Flip(ecran);SDL_Delay(3900);
               printf("win Enigme 3 \n");enigmeDone=4;done=3;terminer3=1;
              } 
              else{sound_wrong();printf("False Enigme 3\n");}
            }
             printf("terminer1 %d terminer2 %d terminer3 %d \n",terminer1,terminer2,terminer3);
             }break;
             case SDLK_LEFT: 
             {
             if(terminer1!=1||terminer2!=1||terminer3!=1)
             {
             printf("i left %d \n",i);
             i--;
             if(i<=0){i=4;}
             if(i==5){i=1;}
             if(i==1){poscurseur.y=435; poscurseur.x=590; SDL_BlitSurface(curseur,NULL,ecran,&poscurseur);  SDL_Flip(ecran); SDL_Delay(900);} 
             if(i==2){poscurseur.y=435; poscurseur.x=770; SDL_BlitSurface(curseur,NULL,ecran,&poscurseur); SDL_Flip(ecran); SDL_Delay(900);} 
             if(i==3){poscurseur.y=510; poscurseur.x=590; SDL_BlitSurface(curseur,NULL,ecran,&poscurseur); SDL_Flip(ecran); SDL_Delay(900);}
             if(i==4){poscurseur.y=510; poscurseur.x=770; SDL_BlitSurface(curseur,NULL,ecran,&poscurseur); SDL_Flip(ecran); SDL_Delay(900);}
             }
             }
             break;
             //////////FIN_Case_UP//////////
             case SDLK_RIGHT:
             {
             if(terminer1!=1||terminer2!=1||terminer3!=1)
             {
             printf("i right %d \n",i);
             i++;
             if(i==5){i=1;}
             if(i==1){poscurseur.y=435; poscurseur.x=590; SDL_BlitSurface(curseur,NULL,ecran,&poscurseur);  SDL_Flip(ecran); SDL_Delay(900);} 
             if(i==2){poscurseur.y=435; poscurseur.x=770; SDL_BlitSurface(curseur,NULL,ecran,&poscurseur); SDL_Flip(ecran); SDL_Delay(900);} 
             if(i==3){poscurseur.y=510; poscurseur.x=590; SDL_BlitSurface(curseur,NULL,ecran,&poscurseur); SDL_Flip(ecran); SDL_Delay(900);}
             if(i==4){poscurseur.y=510; poscurseur.x=770; SDL_BlitSurface(curseur,NULL,ecran,&poscurseur); SDL_Flip(ecran); SDL_Delay(900);}
             }
             }
             break;
           }
        }
       clic=bad_signal_Tv(ecran,clic,entrer);
       if(clic==2)
       {
       entrer=start_enigme1(ecran,entrer);
       }
       if(entrer==1)
       {
       if(enigmeDone==1){done=1;affichage(ecran,quiz1);}
       if(enigmeDone==2){done=2;affichage(ecran,quiz2);}
       if(enigmeDone==3){done=3;affichage(ecran,quiz3);}
       if(enigmeDone==3){done=3;affichage(ecran,quiz3);}
       if(enigmeDone==4){affichage(ecran,mabrouk);sound_win();}
       SDL_Flip(ecran);
       }
       
    }

if(enigmeDone==4)
   {
    return win; 
   }
librer_image(quiz1);
librer_image(quiz2);
librer_image(quiz3);
librer_image(mabrouk);
librer_image(correct1);
librer_image(correct2);
librer_image(correct3);
SDL_FreeSurface(curseur);
}

