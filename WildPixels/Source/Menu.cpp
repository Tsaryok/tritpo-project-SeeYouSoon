#include "Menu.hpp"

void Menu::menuRender()
{
	SDL_RenderCopy(Entity::getRenderer(), background, source_, destination_);
	for (Button* button : buttons) 
	{
		button->toRender();
	}
}