#include "Dot.h"

Dot::Dot(int x, int y) {
	_playerScored = false;
	_cpuScored = false;

	_posX = x;
	_posY = y;

	_dot.x = _posX;
	_dot.y = _posY;

	_dot.w = DOT_WIDTH;
	_dot.h = DOT_HEIGHT;

	_velX = DOT_VEL;
	_velY = DOT_VEL;
}

void Dot::move(SDL_Rect playerPaddle, SDL_Rect cpuPaddle) {
	_playerScored = false;
	_cpuScored = false;

	//Move the dot left or right
	_posX += _velX;
	_dot.x = _posX;

	//If the dot collided or went too far to the left or right
	if (SDL_HasIntersection(&_dot, &playerPaddle))
	{
		_velX = DOT_VEL;
		_posX += _velX;
		_dot.x = _posX;
	}

	if (_posX <= 0)
	{
		_cpuScored = true;

		_posX = 640 / 2;
		_posY = 480 / 2;

		_dot.x = _posX;
		_dot.y = _posY;
	}

	if (SDL_HasIntersection(&_dot, &cpuPaddle)) {
		_velX = 0 - DOT_VEL;
		_posX += _velX;
		_dot.x = _posX;
	}

	if (_posX + DOT_WIDTH >= 640) {
		_playerScored = true;

		_posX = 640 / 2;
		_posY = 480 / 2;

		_dot.x = _posX;
		_dot.y = _posY;
	}

	//Move the dot up or down
	_posY += _velY;
	_dot.y = _posY;

	//If the dot collided or went too far up or down
	if (_posY < 0)
	{
		_velY = DOT_VEL;
		_posY += _velY;
		_dot.y = _posY;
	}

	if (_posY + DOT_HEIGHT > 480) {
		_velY = 0 - DOT_VEL;
		_posY += _velY;
		_dot.y = _posY;
	}
}

void Dot::render(SDL_Renderer* renderer) {
	_dot = { _posX, _posY, DOT_WIDTH, DOT_HEIGHT };
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderFillRect(renderer, &_dot);
}