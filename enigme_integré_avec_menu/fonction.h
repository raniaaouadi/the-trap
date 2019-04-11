#ifndef FONCTION_H_
#define FONCTION_H_

typedef struct image
{
	SDL_Surface *back;
	SDL_Rect posPicture;
}image;
///////////////////////////////////////////////////////////
typedef struct
{
    int heur1;
    int minute1;
    int seconde1;
    int maxtemp;
    SDL_Color textcolor;
    SDL_Surface *temp;
    SDL_Rect position_temp;
    TTF_Font *police ;
    int tempactuel;
    int tempprecedent;
    SDL_Rect position_imgtemp;
    SDL_Surface *imgtemp;
    char chaine[20];
}tempss;
///////////////////////////////////////////////////////////
typedef struct 
{
SDL_Rect position ;  
int val ;
SDL_Surface *image[5]; 
} vie ;
//////////////////////////////////////////////////////////
typedef struct 
{
TTF_Font *police;
SDL_Rect position ;  
SDL_Surface *texte;
int tempsActuel;
int  tempsPrecedent ;
int  compteur;
char chaine[20];
}score; 
/////////////////////////////////////////////////////////
image init_image(char nameofpicture[100],int x,int y);
void affichage(SDL_Surface *ecran,image img);
void librer_image(image img);

void Music_annimation();
void sound_Glass();
void sound_signal();
void Music_read_this();
void Music_start_enigme1();
void sound_wrong();
void sound_correct();
void sound_win();

void annimation_enigme1(SDL_Surface *ecran);
void click_here_pls(SDL_Surface *ecran);
int start_enigme1(SDL_Surface *ecran,int entrer);
int bad_signal_Tv(SDL_Surface *ecran,int clic,int entrer);
//////////////////////////////////////////////////////////////
tempss inisaliser_temp_compteur (tempss temp,int diff);
tempss gestion_temps_compteur(int pause_time_disc,int pause_time_pause,tempss temp,SDL_Surface *ecran);

void free_temps(tempss temp);

tempss inisaliser_temp_decompteur (tempss temp,int diff );
tempss gestion_temps_decompteur(int pause_time_disc,int pause_time_pause,tempss temp,SDL_Surface *ecran);
//////////////////////////////////////////////////////////////
vie init_vie(vie v) ; 
vie updatevie(vie v,int gagne,SDL_Surface *ecran); 
void displayvie(vie v ,SDL_Surface *ecran) ;  
void vie_freevie(vie v ) ;  
//////////////////////////////////////////////////////////////
score intialiser_score(score s);
score  gestion_score(score s,SDL_Surface *ecran);
void afficher_score(score s,SDL_Surface *ecran);
void free_score(score s,SDL_Surface *ecran);
//////////////////////////////////////////////////////////////
void debut(SDL_Surface *ecran);
void menu(SDL_Surface *ecran);
void Music_menu();

#endif
