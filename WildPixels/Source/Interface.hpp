#pragma once
#include "Observer.hpp"
#include <SDL.h>

class Interface
{
public:
	static void keyboardHandler()
	{
		SDL_Event kEvent;

		while (SDL_PollEvent(&kEvent) != 0)
		{
			if (kEvent.type == SDL_KEYDOWN)
			{
				switch (kEvent.key.keysym.sym) {
				case SDLK_d:
					Observer::toActionTrying(MainCharacter::Right);
					break;
				case SDLK_a:
					Observer::toActionTrying(MainCharacter::Left);
					break;
				case SDLK_j:
					Observer::toActionTrying(MainCharacter::Attack1);
					break;
				case SDLK_k:
					Observer::toActionTrying(MainCharacter::Attack2);
					break;
				case SDLK_l:
					Observer::toActionTrying(MainCharacter::Attack3);
					break;
				case SDLK_f:
					Observer::toActionTrying(6);
				}
			}
			if (kEvent.type == SDL_KEYUP)
			{
				Observer::toActionTrying();
			}
		}
	}
};