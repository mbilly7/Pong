#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

class Text
{
public:
	Text(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, std::string message, std::string font, SDL_Renderer* renderer);
	~Text();

	void setMessage(std::string message);
	void render(SDL_Renderer* renderer);
private:
	int _x, _y;

	std::string _message;

	SDL_Surface* _messageSurface;
	SDL_Texture* _messageTexture;
	SDL_Rect _messageRect;
	SDL_Color _color;

	TTF_Font* _font;
};
