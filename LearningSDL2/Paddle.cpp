#include "Paddle.h"
#include <iostream>

Paddle::Paddle(int x, int y, int width, int height) {
	_x = x;
	_y = y;
	_width = width;
	_height = height;
}

void Paddle::playerMove(SDL_Event e) {
	bool quit = false;

	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			if (_y >= 0)
				_y -= PADDLE_SPEED;

			break;
		case SDLK_DOWN:
			if ((_y + _height) <= 480)
				_y += PADDLE_SPEED;

			break;
		default:
			break;
		}
	}
}

void Paddle::cpuMove(SDL_Rect ball) {
	if (ball.y > _rect.y && ball.y < (480 - _height / 2)) {
		_y += PADDLE_SPEED - 2;
	}
	else if (ball.y < _rect.y) {
		_y -= PADDLE_SPEED - 2;
	}
}

void Paddle::render(SDL_Renderer* renderer) {
	_rect = { _x, _y, _width, _height };
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderFillRect(renderer, &_rect);
}