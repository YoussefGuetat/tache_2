#include "enemy.h"


void main()
{
    //declare simple variables
    int done = 1;
    enemie f;
	

    bool running=true;
	SDL_Event event;

SDL_Init(SDL_INIT_VIDEO );

    SDL_Surface *screen, *bg, *hero;

    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Lunatics", NULL); //window title

    SDL_Rect bgPos;
    bgPos.x = 0;
    bgPos.y = 0;

bg = IMG_Load("Assets/graphic/stages/backgtest.jpg");


    SDL_Rect heropos;
    heropos.x = 20;
    heropos.y = 480;
    heropos.w=200;
    heropos.h=200;

hero = IMG_Load("Assets/graphic/hero/hero_test.png");


	inisialiser_enemie (&f);

SDL_EnableKeyRepeat(200,0);
while(running)
{

while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
		done = 0;
        SDL_Quit();
			running=false;
		break;
        case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
                //pause screen
		done = 0;
        SDL_Quit();
			running=false;

                break;
                
                case SDLK_RIGHT:
			heropos.x +=30;	
                break;

                case SDLK_LEFT :
				heropos.x -=30;
      		     break;
				case SDLK_UP :
				heropos.y -=30;
				break;
				case SDLK_DOWN :
				heropos.y +=30;

			}
		break;

        case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
			break;
			case SDLK_LEFT :
      		break;

			}
		break;
	    }
    }

// pos ennemi
SDL_Rect relcoord={f.rect.x , f.rect.y};
//
SDL_Rect relcoord1={f.rect.x , f.rect.y , f.rect.h , f.rect.w};

/*


int collision=0;
collision = collision_BB(heropos ,relcoord1 );
if(collision == 1)
{
heropos.y+=10;
}
*/
 update_ennemi(&f , screen , heropos );

//MoveEnnemi(&f);
SDL_BlitSurface(bg, NULL, screen, &bgPos);
SDL_BlitSurface(hero, NULL, screen, &heropos);
afficher_enemie (&f,screen ,relcoord);


SDL_Flip(screen);
SDL_Delay(16);

}
}
