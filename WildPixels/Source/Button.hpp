#pragma once
#include "Entity.hpp"
#include <SDL.h>

class Button : public Entity
{
private:
	int buttonType;
	
public:
	enum Buttons
	{
		NewGame,
		Settings,
		Exit
	};

	Button(const int destinationX, const int destinationY, int button) : Entity(destinationX, destinationY)
	{
		buttonType = button;
		std::vector<std::string> buttonName = { "new_game", "settings", "exit" };
		const char* basicImagesPath = "Resource\\images\\menu\\button\\";
		currentTexture_ = loadMetaDataTexture(basicImagesPath + buttonName[button]);

		source_->w = currentTexture_.infoImage.widthFrame;
		source_->h = currentTexture_.infoImage.heightFrame;
		destination_->w = currentTexture_.infoImage.widthFrame;
		destination_->h = currentTexture_.infoImage.heightFrame;
		destination_->x = destinationX;
		destination_->y = destinationY;
	}

	bool handleEvent(SDL_Event* event)
	{		
		if (event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN)
		{
			int x, y;
			bool inside = true;
			SDL_GetMouseState(&x, &y);
			
			if (x < getObjectPosition().x)
			{
				inside = false;
			}
			else if (x > getObjectPosition().x + source_->w)
			{
				inside = false;
			}
			else if (y < getObjectPosition().y)
			{
				inside = false;
			}
			else if (y > getObjectPosition().y + source_->h)
			{
				inside = false;
			}
			if (!inside)
			{
				source_->x = 0;
				source_->y = 0;
			}
			else
			{
				switch (event->type)
				{
				case SDL_MOUSEMOTION:
					source_->x = currentTexture_.infoImage.widthFrame;
					break;

				case SDL_MOUSEBUTTONDOWN:
					return true;
				}
			}
		}
		return false;
	}

	void toRender()
	{
		SDL_RenderCopy(renderer_, currentTexture_.texture, source_, destination_);
	}
	
	int getButtonType()
	{
		return buttonType;
	}
};