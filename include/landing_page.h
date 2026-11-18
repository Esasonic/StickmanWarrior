#ifndef LANDING_PAGE_H
#define LANDING_PAGE_H

#include <stdbool.h>
#include <SDL3/SDL.h>

void afficher_landing_page(SDL_Renderer *renderer, int largeur, int hauteur);
bool clic_landing_page(float x, float y, int largeur, int hauteur);

#endif
