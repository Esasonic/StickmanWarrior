
#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "include/player.h"

#include "stickman.h"
#include "landing_page.h"

//variables globales
static SDL_Window *window = NULL;
SDL_Renderer * first_context;

int wScreen, hScreen;

float stickman_x;
float stickman_y;
static bool go_right;
static bool go_left;
int initialized = 0;
static bool jeu_commence = false;

Player player;

//initiialisation
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]){
  SDL_SetAppMetadata("StickmanWarrior", "1", "ESGI_HOMEWORK");
  if(!SDL_Init(SDL_INIT_VIDEO)) return SDL_APP_FAILURE;
  window = SDL_CreateWindow("StickmanWarrior", 500, 500, SDL_WINDOW_FULLSCREEN);
  first_context = SDL_CreateRenderer(window, NULL);

  initPlayer(&player);

  return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate){
        if(initialized < 10){
        SDL_GetCurrentRenderOutputSize(first_context, &wScreen, &hScreen);
                stickman_x = wScreen / 2.0f;
                stickman_y = hScreen / 2.0f;
                initialized++;
        }

        if(!jeu_commence){
                afficher_landing_page(first_context, wScreen, hScreen);
                SDL_RenderPresent(first_context);
                return SDL_APP_CONTINUE;
        }

        SDL_SetRenderDrawColor(first_context, 0,0,0, 255);
        SDL_RenderClear(first_context);

        if(go_right) stickman_x +=1;
        if(go_left) stickman_x -=1;

        render_stickman(first_context, stickman_x, stickman_y);

        SDL_RenderPresent(first_context);

    return SDL_APP_CONTINUE;
  }

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
        go_right = false;
        go_left = false;

  if(event->type == SDL_EVENT_QUIT) return SDL_APP_SUCCESS;

  if(!jeu_commence && event->type == SDL_EVENT_MOUSE_BUTTON_DOWN){
    if(SDL_ConvertEventToRenderCoordinates(first_context, event) &&
       clic_landing_page(event->button.x, event->button.y, wScreen, hScreen)){
      jeu_commence = true;
    }
  }

  if(event->type == SDL_EVENT_KEY_DOWN){
    if(event->key.key == SDLK_ESCAPE){
      return SDL_APP_SUCCESS;
    }
      if(event->key.key == SDLK_D) go_right = true;
      if(event->key.key == SDLK_Q) go_left = true;
  }

  if(event->type == SDL_EVENT_KEY_UP){
        if(event->key.key == SDLK_D) go_right = false;
        if(event->key.key == SDLK_Q) go_left = false;
  }

  return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result){
  SDL_DestroyRenderer(first_context);
  SDL_DestroyWindow(window);
}
