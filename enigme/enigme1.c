#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigme1.h"

image init_image(char nameofpicture[100],int x,int y)
{
image image;
image.back=IMG_Load(nameofpicture);//load image
image.posPicture.x=x;//position x de bg
image.posPicture.y=y;//position y de bg
return image;
}
void affichage(SDL_Surface *ecran,image image)
{
SDL_BlitSurface(image.back,NULL,ecran,&image.posPicture);
}

void librer_image(image image)
{
 SDL_FreeSurface(image.back);//Liberer memoire
}

void Music_annimation()
{
    Mix_Music *Sound_annimation;
    Sound_annimation = Mix_LoadMUS("sound/speaking.mp3");//chargement de la musique
    Mix_VolumeMusic(MIX_MAX_VOLUME / 1);
    Mix_PlayMusic(Sound_annimation,0);//boucle infini
}
void sound_Glass()
{
    Mix_Chunk *glass;
    glass = Mix_LoadWAV("sound/glass.wav");
    Mix_PlayChannel(1,glass,0);
}

void annimation_enigme1(SDL_Surface *ecran)
{
    SDL_Surface *annimation_[1000],*click_here[1000],*bad_signal[1000];
    char annimation[500];
    int i;
    for (i=0;i<=520;i++)//520
    {
        //loading annimation
        sprintf(annimation,"annimation/%d.png",i);
        annimation_[i]=IMG_Load(annimation);
        SDL_BlitSurface(annimation_[i],NULL,ecran,NULL);
        SDL_Flip(ecran);
        printf("[annimation]->i=%d \n",i);
        if(i==1)
        {
        //Music_annimation();
        }
        if(i>1)
        {
            SDL_FreeSurface(annimation_[i]);
        }
        if(i==413)//413
        {
         sound_Glass();
        }
    }
        
}

void click_here_pls(SDL_Surface *ecran)
{
   SDL_Surface *click_here[1000],*fixation=NULL;
   char clickhere[500];
   int annimationDone,nombreclickhere=0,i;
   fixation=IMG_Load("annimation/520.png");
        for (i=1; i<=2&&nombreclickhere!=11; i++)//17
        {
            nombreclickhere++;
            printf("nombre %d \n",nombreclickhere);
            //loading clickhere
            sprintf(clickhere,"click/%d.png",i);
            click_here[i]=IMG_Load(clickhere);
            SDL_BlitSurface(click_here[i],NULL,ecran,NULL);
            SDL_BlitSurface(fixation,NULL,ecran,NULL);
            SDL_BlitSurface(click_here[i],NULL,ecran,NULL);
            SDL_Flip(ecran);
            SDL_Delay(300);
            //printf("[clickhere]->i=%d \n",i);
            if(i>1)
            {
                SDL_FreeSurface(click_here[i]);
            }
            if(i==2)
            {
                i=0;
            }
        }
    
}

void sound_signal()
{
    Mix_Chunk *signal;
    signal= Mix_LoadWAV("sound/signal.wav");
    Mix_PlayChannel(1,signal,0);
}

void Music_read_this()
{
    Mix_Music *Sound_read_this;
    Sound_read_this=Mix_LoadMUS("sound/read_this.mp3");
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
    Mix_PlayMusic(Sound_read_this,0);//boucle infini*/
}

void Music_start_enigme1()
{
    Mix_Music *Sound_start;
    Sound_start=Mix_LoadMUS("sound/start_enigme_1.mp3");
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
    Mix_PlayMusic(Sound_start,-1);//boucle infini*/
}

void sound_correct()
{
    Mix_Chunk *correct;
    correct = Mix_LoadWAV("sound/correct.wav");
    Mix_PlayChannel(1, correct, 0);
}

void sound_wrong()
{
    Mix_Chunk *wrong;
    wrong = Mix_LoadWAV("sound/wrong.wav");
    Mix_PlayChannel(1, wrong, 0);
}

void sound_win()
{
    Mix_Chunk *soundwin;
    soundwin = Mix_LoadWAV("sound/win.wav");
    Mix_PlayChannel(1, soundwin, 0);
}

int start_enigme1(SDL_Surface *ecran,int entrer)
{
   SDL_Event event;
   SDL_Surface *start_enigme[1000];
   char startenigme[500];
   int i;
   
               for (i=1; i<=24&&entrer!=1 ;i++)
               {
                //loading start
                sprintf(startenigme,"start/%d.png",i);
                start_enigme[i]=IMG_Load(startenigme);
                SDL_BlitSurface(start_enigme[i],NULL,ecran,NULL);
                SDL_Flip(ecran);
                printf("start=%d \n",i);
                if(i>1)
                {
                    SDL_FreeSurface(start_enigme[i]);
                }
                if(i==1){Music_start_enigme1();}
                if(i==24){i=1;}
        SDL_PollEvent(&event);
        switch(event.type)
        {
                break;
            case SDL_KEYDOWN:
           switch(event.key.keysym.sym)
           {case SDLK_RETURN:entrer=1;break;}
        }
              }
return entrer;
}

int bad_signal_Tv(SDL_Surface *ecran,int clic,int entrer)
{
   SDL_Surface *bad_signal[1000],*parole=NULL;
   char badsignal[500];
   int i,k=0,j;
        if(clic==1)
        {
            parole=IMG_Load("img/parole.png");
            for (i=1; i<=24; i++)
            {
                //loading BadSignal
                sprintf(badsignal,"BadSignal/%d.png",i);
                bad_signal[i]=IMG_Load(badsignal);
                SDL_BlitSurface(bad_signal[i],NULL,ecran,NULL);
                SDL_Flip(ecran);

                printf("[badsignal]->i=%d \n",i);
                if(i==1)
                {
                    sound_signal();
                    Music_read_this();
                }
                if(i>1)
                {
                    Music_read_this();
                    SDL_FreeSurface(bad_signal[i]);
                    printf("Free[badsignal]->i=%d \n",i);
                }
                if(i>23)
                {
                    SDL_BlitSurface(parole,NULL,ecran,NULL);
                    SDL_Flip(ecran);
                }
                if(i==24)
                {
                        for (j=1; j<=70; j++)//70
                        {
                         k++;
                         SDL_Delay(300);
                         printf("k=%d \n",k);
                        }
                    if(k==70)
                    {
                       clic=2;
                    }
                }
            }
        }
    return clic;
}


