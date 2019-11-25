#pragma once
#include <vector>
#include <string>
#include "Button.hpp"
#include "Values.hpp"

class Menu
{
	SDL_Texture* background;
	SDL_Rect* source_;
	SDL_Rect* destination_;

public:
	vector<Button*> buttons;
	Menu()
	{
		int buttonX = 241, buttonY = 109, offset = 100;
		for (int i = 0; i < 3; i++)
		{
			buttons.push_back(new Button(buttonX, buttonY + i * offset, i));
		}
		background = Entity::loadTexture("Resource\\images\\menu\\background\\image.png");
		ifstream inputFile("Resource\\images\\menu\\background\\info.txt");
		int w, h;
		inputFile >> w >> h;

		source_ = new SDL_Rect;
		destination_ = new SDL_Rect;
		source_->x = 0;
		source_->y = 0;
		source_->w = w;
		source_->h = h;
		destination_->x = 0;
		destination_->y = 0;
		destination_->w = Values::SCREEN_WIDTH;
		destination_->h = Values::SCREEN_HEIGHT;
	}

	void menuRender();
};
