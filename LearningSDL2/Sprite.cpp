#include "Paddle.h"
#include <iostream>

Paddle::Paddle(int x, int y, int width, int height) {
	_x = x;
	_y = y;
	_spriteWidth = width;
	_spriteHeight = height;
}

void Paddle::move(SDL_Event e) {
	bool quit = false;

	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			_y -= 5;
			break;
		case SDLK_DOWN:
			_y += 5;
			break;
		case SDLK_LEFT:
			_x -= 0;
			break;
		case SDLK_RIGHT:
			_x += 0;
			break;
		default:
			break;
		}
	}
}

void Paddle::render(SDL_Renderer* renderer) {
	_rect = { _x, _y, _spriteWidth, _spriteHeight };
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderFillRect(renderer, &_rect);
}