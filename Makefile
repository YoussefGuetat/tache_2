lunatics:main.o enemy.o
	gcc main.o enemy.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -o lunatics -g; ./lunatics
main.o:main.c
	gcc -c main.c -g



