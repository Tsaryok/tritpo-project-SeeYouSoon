#pragma once
#include "Object.hpp"

class CollisionObject : public Object
{
public:
	CollisionObject(const int destinationX, const int destinationY, int border) : Object(destinationX, destinationY)
	{
		string basicPath = "Resource\\images\\Objects\\borders\\";
		if (border)
		{
			basicPath += "floor";
		}
		else
		{
			basicPath += "wall";
		}
		currentTexture_ = loadMetaDataTexture(basicPath);
		source_->w = currentTexture_.infoImage.widthImage;
		source_->h = currentTexture_.infoImage.heightImage;
		destination_->w = currentTexture_.infoImage.widthImage;
		destination_->h = currentTexture_.infoImage.heightImage;
	}

	enum Borders
	{
		Wall,
		Floor
	};

	void stateMachine() override {}
};

