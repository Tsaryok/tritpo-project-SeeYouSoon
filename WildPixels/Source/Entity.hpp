#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <fstream>
#include <vector>

using namespace std;

class Entity//Сделать виртуальный деструктор
{

public:
	enum SideOrientation
	{
		Right = 1,
		Left = 2
	};
	struct ObjectPosition
	{
		int x;
		int y;
	};
	static struct MapSize
	{
		int width;
		int height;
	}mapSize;
	
	static void setRenderer(SDL_Renderer* renderer)
	{
		renderer_ = renderer;
	}
	static SDL_Renderer* getRenderer()
	{
		return renderer_;
	}

	SDL_Rect getDestination()
	{
		return *destination_;
	}
	
	ObjectPosition getObjectPosition()
	{
		return objectPosition_;
	}

	static SDL_Texture* loadTexture(const char* path);
	Mix_Chunk* loadEffect(string path);

	virtual void stateMachine();
	void toRender();

private:
	int orientation_;
	ObjectPosition objectPosition_{};
	
protected:
	struct MetaDataImage
	{
		int widthImage;
		int heightImage;
		int widthFrame;
		int heightFrame;
		int framesNumber;
		int frequencyDivider;
		int step;
	};
	struct MetaDataTexture
	{
		SDL_Texture* texture;
		MetaDataImage infoImage;
	}currentTexture_;

	int frameCounter_;
	int delayCounter_;

	vector<Mix_Chunk*> effects_;
	Mix_Chunk* currentEffect_;
	SDL_Rect* source_;
	SDL_Rect* destination_;
	static SDL_Renderer* renderer_;

	Entity(int destinationX = 0, int destinationY = 0)
	{
		orientation_ = Right;
		frameCounter_ = 1;
		delayCounter_ = 0;
		objectPosition_.x = destinationX;
		objectPosition_.y = destinationY;
		this->source_ = new SDL_Rect;
		source_->x = 0;
		source_->y = 0;
		this->destination_ = new SDL_Rect;
	}
	virtual ~Entity() = default;//сделать очистку динамической памяти

	void setObjectPosition(int x, int y)
	{
		objectPosition_.x = x;
		objectPosition_.y = y;
	}
	void setOrientation(int orientation);
	int getOrientation();
	int getFrameCounter()
	{
		return frameCounter_;
	}
	int getDelayCounter()
	{
		return delayCounter_;
	}

	void changeSourceCoordinates();
	void changeDestinationCoordinates();
	void beginAnimationsCycle();

	MetaDataTexture loadMetaDataTexture(string actionPath);
};