#include "Text.h"

Text::Text(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, std::string message, std::string font, SDL_Renderer* renderer) {
	_x = x;
	_y = y;
	_message = message;
	_messageRect = { x, y, width, height };

	_font = TTF_OpenFont(font.c_str(), 24);

	if (_font == nullptr) {
		std::cout << "Could not open font." << TTF_GetError() << std::endl;
	}

	_color = { r, g, b };

	_messageSurface = TTF_RenderText_Solid(_font, _message.c_str(), _color);

	if (_messageSurface == nullptr) {
		std::cout << "Could not create message surface. " << SDL_GetError() << std::endl;
	}
	else {
		_messageTexture = SDL_CreateTextureFromSurface(renderer, _messageSurface);

		if (_messageTexture == nullptr) {
			std::cout << "Could not create texture from surface." << SDL_GetError() << std::endl;
		}
	}

	SDL_FreeSurface(_messageSurface);
}

Text::~Text() {
	SDL_DestroyTexture(_messageTexture);
}

void Text::setMessage(std::string message) {
	_message = message;
}

void Text::render(SDL_Renderer* renderer) {
	_messageSurface = TTF_RenderText_Solid(_font, _message.c_str(), _color);
	_messageTexture = SDL_CreateTextureFromSurface(renderer, _messageSurface);

	SDL_RenderCopy(renderer, _messageTexture, nullptr, &_messageRect);
}