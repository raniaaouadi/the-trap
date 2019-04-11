#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"

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

void Music_menu()
{
    Mix_Music *menu;
    menu=Mix_LoadMUS("sound/menu.mp3");
    Mix_VolumeMusic(MIX_MAX_VOLUME / 1);
    Mix_PlayMusic(menu,-1);//boucle infini*/
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
                         printf("k= %d \n",k);
                        }
                    if(k==70)//70
                    {
                       clic=2;
                    }
                }
            }
        }
    return clic;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////:
tempss inisaliser_temp_compteur (tempss temp,int diff)
{
if(diff==1)
{
temp.heur1=0;
temp.minute1=0;
temp.seconde1=0;

temp.tempactuel=0;
SDL_Color textcolor={33,33,33};/*couleurNoire = {33, 33, 33},couleurBlanche = {255, 255, 255},violet = {146, 87, 226} */
temp.temp=NULL;

temp.tempprecedent=0;
strcpy(temp.chaine,"");
temp.position_temp.x=100; //200
temp.position_temp.y=0;
temp.police=TTF_OpenFont("arial.ttf",40);
temp.imgtemp=IMG_Load("img.jpg");
temp.position_imgtemp.x=0;
temp.position_imgtemp.y=0;
temp.maxtemp=300;  
    return temp;
}
else if(diff==2)
{
temp.heur1=0;
temp.minute1=0;
temp.seconde1=0;

temp.tempactuel=0;
SDL_Color textcolor={33, 33, 33} ;  /*couleurNoire = {33, 33, 33}, couleurBlanche = {255, 255, 255}, rose = {85.1, 50.6, 57.3},violet = {146, 87, 226} */
temp.temp=NULL;

temp.tempprecedent=0;
strcpy(temp.chaine,"");
temp.position_temp.x=400;
temp.position_temp.y=0;
temp.police=TTF_OpenFont("arial.ttf",40);
temp.imgtemp=IMG_Load("img.jpg");
temp.position_imgtemp.x=400;
temp.position_imgtemp.y=0;
temp.maxtemp=600;  
    return temp;
}

}

tempss gestion_temps_compteur(int pause_time_disc,int pause_time_pause,tempss temp,SDL_Surface *ecran)
{              
      if((pause_time_disc==0)&&(pause_time_pause==0)&&(temp.maxtemp!=0))     
   {    //      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));   

        temp.tempactuel = SDL_GetTicks();
        if (temp.tempactuel - temp.tempprecedent >=500)
        {

            temp.seconde1 += 1;
           
            if(temp.seconde1 == 60)
            {
               temp.seconde1 = 0;
               temp.minute1+=1;
            }
            if(temp.minute1==60)
            {
               temp.seconde1 =0;
              
               temp.minute1 =0;
               temp.heur1+=1;
            }
            if(temp.heur1==60)
            {
               temp.seconde1 = 0;
               
               temp.minute1 =0;
               temp.heur1=0;

            }

           sprintf(temp.chaine, "%02d : %02d : %02d ",temp.heur1,temp.minute1,temp.seconde1 );
           
           temp.temp = TTF_RenderText_Solid(temp.police, temp.chaine, temp.textcolor);
           temp.tempprecedent=temp.tempactuel;
        }
     
        //SDL_BlitSurface(temp.imgtemp, NULL, ecran,&temp.position_imgtemp);   
        SDL_BlitSurface(temp.temp, NULL, ecran, &temp.position_temp);
        SDL_Flip(ecran);
        
    return temp;
  }
return temp;           
}

void free_temps(tempss temp)
{
TTF_CloseFont(temp.police);
TTF_Quit();
SDL_FreeSurface(temp.temp);
SDL_FreeSurface(temp.imgtemp);
printf("free temps => done \n");
}

/////////////////////////////////////////////////////////////////////////////////////

vie init_vie(vie v) 
{

 (v.position.x)=400;
 (v.position.y)=0;
 (v.val)=0 ;
 v.image[0]=IMG_Load("v0.png") ;
 v.image[1]=IMG_Load("v1.png") ;
 v.image[2]=IMG_Load("v2.png") ;
 v.image[3]=IMG_Load("v3.png") ;
return v;
}

vie updatevie(vie v,int gagne,SDL_Surface *ecran) 
{

if(gagne==3)
{   
    v.val=1;
}
return v;
}

void displayvie(vie v ,SDL_Surface *ecran) 
{
SDL_BlitSurface(v.image[v.val],NULL,ecran,&v.position);
SDL_Flip(ecran);

}

void vie_freevie(vie v ) 
{
SDL_FreeSurface(v.image[0]);
SDL_FreeSurface(v.image[1]);
SDL_FreeSurface(v.image[2]);
SDL_FreeSurface(v.image[3]);
}

////////////////////////////////////////////////////////////////
score intialiser_score(score s)
{
    SDL_Color textcolor={33, 33, 33} ; 
    strcpy(s.chaine,"");
    s.tempsActuel = 0;
    s.tempsPrecedent = 0;
    s.compteur =50;
    s.police = TTF_OpenFont("arial.ttf", 20); 
    s.position.x = 630;
    s.position.y = 0;
    return s;    
}

score  gestion_score(score s,SDL_Surface *ecran)
{
      SDL_Color couleurNoire = {30, 30, 30};
      SDL_Color  couleurBlanche = {255, 255, 255};
        
      sprintf(s.chaine, "score : %05d", s.compteur); 
      s.texte = TTF_RenderText_Shaded(s.police, s.chaine, couleurNoire,couleurBlanche); 

        s.tempsActuel = SDL_GetTicks();
        if (s.tempsActuel - s.tempsPrecedent >= 5000) 
        {
            s.compteur += 10;
            sprintf(s.chaine, "score : %04d", s.compteur); 
            SDL_FreeSurface(s.texte);
            s.texte = TTF_RenderText_Shaded(s.police, s.chaine, couleurNoire,couleurBlanche); 
            s.tempsPrecedent = s.tempsActuel; 
            
	}
    return s;
}

void afficher_score(score s,SDL_Surface *ecran)
{  
    SDL_SetColorKey(s.texte, SDL_SRCCOLORKEY, SDL_MapRGB(s.texte->format, 255, 255, 255));
    SDL_BlitSurface(s.texte, NULL, ecran, &s.position);
    SDL_Flip(ecran);   
}

void free_score(score s,SDL_Surface *ecran)
{
TTF_CloseFont(s.police);
TTF_Quit();
SDL_FreeSurface(s.texte);
printf("free score => done \n");
}

////////////////////////////////////////////////////////////////////////////:
void debut(SDL_Surface *ecran)
{
    SDL_Surface *annimation_menu[1000];
    char annimationmenu[500];
    int i,j;

             for (i=1; i<=139;i++)
             {
                sprintf(annimationmenu,"menu/animation/%d.png",i);
                annimation_menu[i]=IMG_Load(annimationmenu);
                SDL_BlitSurface(annimation_menu[i],NULL,ecran,NULL);
                SDL_Flip(ecran);
                if(i>1)
                {
                    SDL_FreeSurface(annimation_menu[i]);
                }
              }
} 

void menu(SDL_Surface *ecran)
{

SDL_Surface *menu_[1000];
char menu[500];
int j=1,p,i;
image settings,exit,start;
    start=init_image("menu/start.png",13,45);
    settings=init_image("menu/setings.png",13,103);
    exit=init_image("menu/exit.png",13,161);

            while(j!=35 && p <=100)
             {
                j++;
                
                if(j==35)
                {j=1;
                for(i=0;i<=35;i++)
                {
                 p++;
                 printf("p %d \n",p);
                }
                }
                sprintf(menu,"menu/menu/%d.png",j);
                menu_[j]=IMG_Load(menu);
                SDL_BlitSurface(menu_[j],NULL,ecran,NULL);
                SDL_Delay(70);
                SDL_Flip(ecran);
                //printf("menu=%d \n",j);
                if(j>1)
                {
                    SDL_FreeSurface(menu_[j]);
                }
                affichage(ecran,start);
                affichage(ecran,settings);
                affichage(ecran,exit);
                SDL_Flip(ecran);
             }
   
    //printf("choix fnct %d \n",choix); 
librer_image(start);
librer_image(settings);
librer_image(exit);              
}


