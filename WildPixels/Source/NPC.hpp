#pragma once
#include <SDL.h>
#include "Character.hpp"

using namespace std;

class NPC : public Character
{
public:
	enum actions
	{
		STATIC_1,
		NUMBER_OF_ACTIONS
	};

	NPC() {};
	NPC(SDL_Texture* texture[NUMBER_OF_ACTIONS], SDL_Renderer* renderer, SDL_Rect* source, SDL_Rect* destination)
	{
	}
};