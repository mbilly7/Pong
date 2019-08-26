#pragma once
#include "SDL.h"

class Paddle
{
public:
	Paddle(int x, int y, int spriteWidth, int spriteHeight);

	void move(SDL_Event e);
	void render(SDL_Renderer* renderer);

private:
	int _x, _y, _spriteWidth, _spriteHeight;
	SDL_Rect _rect;
};

