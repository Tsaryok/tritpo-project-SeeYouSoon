#include <iostream>
#include <SDL.h>
#include "GameInit.hpp"
#include "ObjectStorage.hpp"
#include "Interface.hpp"
#include "Menu.hpp"
#include "Button.hpp"

using namespace std;

int main(int argc, char* args[])
{
	if (!GameInit::init())
	{
		cout << "Failed to initialize!" << endl;
		return 1;
	}
	else
	{
		bool quitGame = false;
		bool quitGamePlay= false;
		bool quitMenu = false;

		ObjectStorage *objects = new ObjectStorage();
		Menu menu;

		int animationSpeed = 10;//вынести в values
		SDL_Event event;
		while (!quitGame)
		{
			while (!quitMenu)
			{
				SDL_PumpEvents();
				if (SDL_PeepEvents(&event, 1, SDL_PEEKEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT) != 0)
				{
					if (event.type == SDL_KEYDOWN)
					{
						if (event.key.keysym.sym == SDLK_ESCAPE)
						{
							quitMenu = true;
							quitGamePlay = false;
							SDL_PollEvent(&event);
							break;
						}
					}
				}
				if (SDL_PollEvent(&event) != 0)
				{
					
					for (Button* button : menu.buttons)
					{//сделать прерывание цикла
						if (button->handleEvent(&event))
						{//нужно тут знать энамку для кнопок
							switch (button->getButtonType())
							{
							case button->NewGame:
								quitMenu = true;
								quitGamePlay = false;
								delete(objects);
								objects = new ObjectStorage();
								break;
							case button->Exit:
								quitMenu = true;
								quitGame = true;
								quitGamePlay = true;
								break;
							case button->Settings://еще няма
								printf("Settings\n");
								break;
							}
						}
					}
				}
				SDL_RenderClear(Entity::getRenderer());
				menu.menuRender();
				SDL_RenderPresent(Entity::getRenderer());
			}
			while (!quitGamePlay)
			{
				SDL_PumpEvents();
				if (SDL_PeepEvents(&event, 1, SDL_PEEKEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT) != 0)
				{
					if (event.type == SDL_KEYDOWN)
					{
						if (event.key.keysym.sym == SDLK_ESCAPE)
						{
							quitMenu = false;
							quitGamePlay = true;
							SDL_PollEvent(&event);
							break;
						}
					}
				}
				SDL_RenderClear(Entity::getRenderer());
				Interface::keyboardHandler();
				Observer::toCamera();
				objects->gameStep();
				SDL_Delay(animationSpeed);
				SDL_RenderPresent(Entity::getRenderer());
			}
		}
	}
	GameInit::close();

	return 0;
}