#ifndef ENIGME1_H_
#define ENIGME1_H_
typedef struct image
{
	SDL_Surface *back;
	SDL_Rect posPicture;
}image;

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

#endif
