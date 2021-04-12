#ifndef enemy_H_INCLUDED
#define enemy_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>



typedef struct 
	{

	SDL_Surface *enemie;
	SDL_Rect rect;
	SDL_Rect rects[90];
	int frame;
	int direction;
	}enemie;

void setrects_enemie(SDL_Rect* clip);

    void inisialiser_enemie (enemie *f);
    void MoveEnnemi(enemie *E);
	void afficher_enemie (enemie *f,SDL_Surface *screen , SDL_Rect pos);
	void animation (enemie *p);
    int collision_BB(SDL_Rect pos_hero , SDL_Rect pos_e );
  void update_ennemi(enemie *e , SDL_Surface *screen , SDL_Rect pos_hero );

#endif // DS_H_INCLUDED