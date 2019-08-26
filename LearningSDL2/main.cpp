#include "SDL.h"
#include "Paddle.h"
#include "Dot.h"
#include "Text.h"
#include <iostream>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);

	if (TTF_Init() == -1) {
		std::cout << "Could not initialize TTF." << std::endl;
	}

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Event e;

	Paddle playerPaddle(10, (SCREEN_HEIGHT / 2 - 25), 25, 50);
	Paddle cpuPaddle((SCREEN_WIDTH - 35), (SCREEN_HEIGHT / 2 - 25), 25, 50);

	Dot ball(325, 235);

	int playerScore = 0;
	int cpuScore = 0;

	bool quit = false;

	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		std::cout << "Could not display window." << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		std::cout << "Could not create renderer." << SDL_GetError() << std::endl;
	}

	Text scorePlayer((SCREEN_WIDTH / 4 - 50), 10, 100, 50, 255, 255, 255, "0", "arial.ttf", renderer);
	Text scoreCPU((SCREEN_WIDTH * 0.75 - 50), 10, 100, 50, 255, 255, 255, "0", "arial.ttf", renderer);

	while (!quit) {
		SDL_PollEvent(&e);

		if (e.type == SDL_QUIT) {
			quit = true;
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		if (ball.playerHasScored() || ball.cpuHasScored()) {
			SDL_Delay(1000);
		}

		ball.move(playerPaddle.getPaddle(), cpuPaddle.getPaddle());
		playerPaddle.playerMove(e);
		cpuPaddle.cpuMove(ball.getDot());

		ball.render(renderer);
		playerPaddle.render(renderer);
		cpuPaddle.render(renderer);

		if (ball.playerHasScored()) {
			playerScore++;

			scorePlayer.setMessage(std::to_string(playerScore));
		}
		else if (ball.cpuHasScored()) {
			cpuScore++;

			scoreCPU.setMessage(std::to_string(cpuScore));
		}

		scorePlayer.render(renderer);
		scoreCPU.render(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_Quit();
	TTF_Quit();

	return 0;
}