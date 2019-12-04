#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include "Entity.hpp"
#include "Camera.hpp"
#include "Observer.hpp"

using namespace std;

SDL_Renderer* Entity::renderer_ = nullptr;
Entity::MapSize Entity::mapSize{};

void Entity::toRender()
{
	destination_->x = objectPosition_.x - Camera::x;
	destination_->y = objectPosition_.y - Camera::y;
	SDL_RenderCopy(renderer_, currentTexture_.texture, source_, destination_);
}
void Entity::changeSourceCoordinates()
{
	if (delayCounter_ < currentTexture_.infoImage.frequencyDivider)
	{
		delayCounter_++;
	}
	else
	{
		delayCounter_ = 0;
		if (frameCounter_++ < currentTexture_.infoImage.framesNumber)
		{
			source_->y = source_->y % (currentTexture_.infoImage.heightImage / 2) + (currentTexture_.infoImage.heightImage / 2) * (orientation_ - 1);

			if (source_->x < currentTexture_.infoImage.widthImage - currentTexture_.infoImage.widthFrame)
			{
				source_->x += currentTexture_.infoImage.widthFrame;
			}
			else
			{
				source_->x = 0;
				if (source_->y < currentTexture_.infoImage.heightImage - currentTexture_.infoImage.heightFrame)
				{
					source_->y += currentTexture_.infoImage.heightFrame;
				}
				else
				{
					source_->y = (currentTexture_.infoImage.heightImage / 2) * (orientation_ - 1);
				}
			}
		}
	}
}
void Entity::changeDestinationCoordinates()
{
	if (orientation_ == Right)
	{
		objectPosition_.x += currentTexture_.infoImage.step;
	}
	else
	{
		objectPosition_.x -= currentTexture_.infoImage.step;
	}
	if (Observer::collisionDetection(this))
	{
		if (orientation_ == Right)
		{
			objectPosition_.x -= currentTexture_.infoImage.step;
		}
		else
		{
			objectPosition_.x += currentTexture_.infoImage.step;
		}
	}
	Observer::battleDetection();
}
void Entity::beginAnimationsCycle()
{
	Mix_PlayChannel(2, currentEffect_, 0);
	frameCounter_ = 1;
	source_->x = 0;
	source_->y = (currentTexture_.infoImage.heightImage / 2) * (getOrientation() - 1);
}
void Entity::setOrientation(const int orientation)
{
	if ((this->orientation_ != orientation) && (orientation != 0))
	{
		frameCounter_ = 1;
		delayCounter_ = currentTexture_.infoImage.frequencyDivider;
		this->orientation_ = orientation;
	}
}
int Entity::getOrientation() 
{
	return orientation_;
}
SDL_Texture* Entity::loadTexture(const char* path)
{
	SDL_Texture* final_texture = NULL;
	SDL_Surface* loaded_surface = IMG_Load(path);

	if (loaded_surface == NULL)
	{
		cout << ("Unable to load image %s! SDL Error %s\n: ", path, SDL_GetError()) << endl;
	}
	else
	{
		//SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB(loaded_surface->format, 0xFF, 0xFF, 0xFF));
		final_texture = SDL_CreateTextureFromSurface(getRenderer(), loaded_surface);

		if (final_texture == NULL)
		{
			cout << ("Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError()) << endl;
		}
		SDL_FreeSurface(loaded_surface);
	}
	return final_texture;
}
Mix_Chunk* Entity::loadEffect(string path)
{
	string effectPath(path + "\\effect.wav");
	
	Mix_Chunk* effect = Mix_LoadWAV(effectPath.c_str());
	if (effect == nullptr)
	{
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
	return effect;
}
Entity::MetaDataTexture Entity::loadMetaDataTexture(string actionPath)
{
	MetaDataTexture texture;
	MetaDataImage image;
	string imagePath(actionPath + "\\image.png");
	texture.texture = loadTexture(imagePath.c_str());
	string imageInfoPath(actionPath + "\\info.txt");
	ifstream inputFile(imageInfoPath.c_str());
	inputFile >> image.framesNumber >> image.widthImage >> image.heightImage >>
		image.widthFrame >> image.heightFrame >> image.frequencyDivider >> image.step;
	texture.infoImage = image;
	inputFile.close();
	return texture;
}
void Entity::stateMachine()
{
	
}