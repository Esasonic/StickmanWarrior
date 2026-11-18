
#include "include/stickman.h"

void render_stickman(SDL_Renderer *renderer, float x, float y, int punch_direction, int punch_frame){

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    //corps
    SDL_RenderLine(renderer, x, y, x, y + 80);

    //jambes
    SDL_RenderLine(renderer, x, y + 80, x - 30, y + 150);
    SDL_RenderLine(renderer, x, y + 80, x + 30, y + 150);

    //bras
    if(punch_direction == -1){
        if(punch_frame == 1 || punch_frame == 3){
            SDL_RenderLine(renderer, x, y + 20, x - 50, y + 35);
        }
        else if(punch_frame == 2){
            SDL_RenderLine(renderer, x, y + 20, x - 75, y + 20);
        }
        else{
            SDL_RenderLine(renderer, x, y + 20, x - 40, y + 60);
        }

        SDL_RenderLine(renderer, x, y + 20, x + 40, y + 60);
    }
    else if(punch_direction == 1){
        SDL_RenderLine(renderer, x, y + 20, x - 40, y + 60);

        if(punch_frame == 1 || punch_frame == 3){
            SDL_RenderLine(renderer, x, y + 20, x + 50, y + 35);
        }
        else if(punch_frame == 2){
            SDL_RenderLine(renderer, x, y + 20, x + 75, y + 20);
        }
        else{
            SDL_RenderLine(renderer, x, y + 20, x + 40, y + 60);
        }
    }
    else{
        SDL_RenderLine(renderer, x, y + 20, x - 40, y + 60);
        SDL_RenderLine(renderer, x, y + 20, x + 40, y + 60);
    }

    //tete
    float size = 30;
    SDL_FRect head = {x - size / 2, y - size, size, size };
    SDL_RenderFillRect(renderer, &head);
}
