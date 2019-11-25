#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "GameInit.hpp"
#include "Values.hpp"
#include "Entity.hpp"

using namespace std;

int GameInit::init()
{
	int success = 1;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		cout << ("SDL could not initialize! SDL_Error: %s\n", SDL_GetError()) << endl;
		success = 0;
	}
	else
	{
		Values::window = SDL_CreateWindow("WildPixels", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			Values::SCREEN_WIDTH, Values::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (Values::window == NULL)
		{
			cout << ("Window could not be created! SDL_Error: %s\n", SDL_GetError()) << endl;
			success = 0;
		}
		else
		{
			Entity::setRenderer(SDL_CreateRenderer(Values::window, -1, SDL_RENDERER_SOFTWARE));
			if (Entity::getRenderer() == NULL)
			{
				cout << ("Renderer could not be created! SDL Error: %s\n", SDL_GetError()) << endl;
				success = 0;
			}

			SDL_SetRenderDrawColor(Entity::getRenderer(), 0x00, 0x00, 0x00, 0x00);

			if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
			{
				cout << ("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError()) << endl;
				success = 0;
			}
			if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			{
				printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
				success = 0;
			}
		}
	}
	return success;
}

void GameInit::close()
{//тут нехорошо
	SDL_DestroyRenderer(Entity::getRenderer());
	SDL_DestroyWindow(Values::window);

	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}