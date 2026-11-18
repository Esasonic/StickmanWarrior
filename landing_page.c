#include "include/landing_page.h"
#include <string.h>
static SDL_Texture *fond = NULL;



static SDL_FRect bouton_demarrer(int largeur, int hauteur)
{
    SDL_FRect bouton = {(largeur - 240.0f) / 2.0f, hauteur * 0.55f, 240.0f, 70.0f};
    return bouton;
}


static SDL_FRect bouton_option(int largeur, int hauteur)
{
    SDL_FRect bouton = {(largeur - 240.0f) / 2.0f, hauteur * 0.20 200f, 50f};
    return bouton;
}



void afficher_landing_page(SDL_Renderer *renderer, int largeur, int hauteur)
{
    SDL_SetRenderDrawColor(renderer, 15, 18, 28, 255);
    SDL_RenderClear(renderer);

    if (fond == NULL)
    {
        SDL_Surface *image = SDL_LoadSurface("assets/fond.png");

        if (image != NULL)
        {
            fond = SDL_CreateTextureFromSurface(renderer, image);
            SDL_DestroySurface(image);
        }
        else
        {
            SDL_Log("Erreur image : %s", SDL_GetError());
        }
    }

    if (fond != NULL)
    {
        SDL_RenderTexture(renderer, fond, NULL, NULL);
    }

    const char *titre = "STICKMAN WARRIOR";
    const char *texte = "COMMENCER";
    SDL_FRect bouton = bouton_demarrer(largeur, hauteur);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_SetRenderScale(renderer, 3.0f, 3.0f);

    float titre_x = (largeur - strlen(titre) * 24.0f) / 6.0f;
    float titre_y = hauteur * 0.28f / 3.0f;

    SDL_RenderDebugText(renderer, titre_x, titre_y, titre);
    SDL_SetRenderScale(renderer, 1.0f, 1.0f);

    SDL_SetRenderDrawColor(renderer, 195, 54, 54, 255);
    SDL_RenderFillRect(renderer, &bouton);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_SetRenderScale(renderer, 2.0f, 2.0f);

    float texte_x = (bouton.x + (bouton.w - strlen(texte) * 16.0f) / 2.0f) / 2.0f;
    float texte_y = (bouton.y + (bouton.h - 16.0f) / 2.0f) / 2.0f;

    SDL_RenderDebugText(renderer, texte_x, texte_y, texte);
    SDL_SetRenderScale(renderer, 1.0f, 1.0f);
}




bool clic_landing_page(float x, float y, int largeur, int hauteur)
{
    SDL_FRect bouton = bouton_demarrer(largeur, hauteur);
    return x >= bouton.x && x <= bouton.x + bouton.w &&
           y >= bouton.y && y <= bouton.y + bouton.h;
}
