#include "include/player.h"

void initPlayer(Player *player)
{
    player->x = 250;
    player->y = 250;
    player->direction = 1;
    player->animation = 0;
    player->frame = 0;
}

void drawPlayer(SDL_Renderer *renderer, Player *player)
{
    int x = player->x;
    int y = player->y;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    //tete
    SDL_RenderLine(renderer, x-8, y-40, x+8, y-40);
    SDL_RenderLine(renderer, x-8, y-40, x-8, y-24);
    SDL_RenderLine(renderer, x+8, y-40, x+8, y-24);
    SDL_RenderLine(renderer, x-8, y-24, x+8, y-24);

    //corps
    SDL_RenderLine(renderer, x, y-24, x, y+20);

    //bras
    SDL_RenderLine(renderer, x, y-15, x-20, y);
    SDL_RenderLine(renderer, x, y-15, x+20, y);

    //jambes
    SDL_RenderLine(renderer, x, y+20, x-15, y+45);
    SDL_RenderLine(renderer, x, y+20, x+15, y+45);
}