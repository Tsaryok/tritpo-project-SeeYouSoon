#pragma once
#include "Entity.hpp"
#include "GameInit.hpp"
#include <fstream>

class Background : public Entity
{
public:
	Background()
	{
		string basicPath = "Resource\\images\\Levels";

		currentTexture_ = loadMetaDataTexture(basicPath);
		source_->w = currentTexture_.infoImage.widthImage;
		source_->h = currentTexture_.infoImage.heightImage;
		destination_->w = currentTexture_.infoImage.widthImage;
		destination_->h = currentTexture_.infoImage.heightImage;

		mapSize.width = currentTexture_.infoImage.widthImage;
		mapSize.height = currentTexture_.infoImage.heightImage;
	}
};
