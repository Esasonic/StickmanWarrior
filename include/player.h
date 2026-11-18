#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>

typedef struct
{
    int x;
    int y;
    int direction;
    int animation;
    int frame;
} Player;

void initPlayer(Player *player);

void drawPlayer(SDL_Renderer *renderer, Player *player);

#endif