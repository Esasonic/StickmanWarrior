#include "stickman.h"

void render_stickman(SDL_Renderer *renderer, float x, float y){
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderLine(renderer, x, y, x, y +80);

	SDL_RenderLine(renderer, x, y + 80, x - 30, y + 150);
	SDL_RenderLine(renderer, x, y + 80, x + 30, y + 150);

	SDL_RenderLine(renderer, x, y + 20, x - 40, y + 60);
	SDL_RenderLine(renderer, x, y + 20, x + 40, y + 60);



	
	float size = 30;
	SDL_FRect head = {x - size / 2, y - size, size, size };
	SDL_RenderFillRect(renderer, &head);
}
