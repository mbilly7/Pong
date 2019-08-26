#pragma once
#include <SDL.h>

class Dot
{
public:
	static const int DOT_WIDTH = 10;
	static const int DOT_HEIGHT = 10;
	static const int DOT_VEL = 3;

	Dot(int x, int y);

	SDL_Rect getDot() { return _dot; }

	bool playerHasScored() { return _playerScored; }
	bool cpuHasScored() { return _cpuScored; }

	void move(SDL_Rect playerPaddle, SDL_Rect cpuPaddle);
	void render(SDL_Renderer* renderer);

private:
	int _posX, _posY;
	int _velX, _velY;
	bool _playerScored, _cpuScored;
	SDL_Rect _dot;
};
