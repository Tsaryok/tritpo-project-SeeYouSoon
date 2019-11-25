#pragma once
#include "Object.hpp"
#include <string>

class Chest : public Object
{
private:
	bool isOpened = false;
public:
	Chest(int destinationX, int destinationY) : Object(destinationX, destinationY)
	{
		string basicPath = "Resource\\images\\Objects\\chest";
		currentTexture_ = loadMetaDataTexture(basicPath);
	}
	void stateMachine() override;
};

