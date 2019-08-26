#pragma once
#include "SDL.h"

class Paddle
{
public:
	static const int PADDLE_SPEED = 4;

	Paddle(int x, int y, int width, int height);

	SDL_Rect getPaddle() { return _rect; }

	void playerMove(SDL_Event e);
	void cpuMove(SDL_Rect ball);
	void render(SDL_Renderer* renderer);

private:
	int _x, _y, _width, _height;
	SDL_Rect _rect;
};
