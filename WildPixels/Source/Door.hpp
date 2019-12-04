#pragma once
#include "InteractionObject.hpp"

class Door : public InteractionObject
{
private:
	int counterToClose_;
	Door* otherDoor;
public:
	enum State
	{
		Close,
		Open,
		NumberStates
	};
	Door() = delete;
	Door(const int destinationX, const int destinationY) : InteractionObject(destinationX, destinationY)
	{
		const char* basicImagePath = "Resource\\images\\Objects\\door";

		currentTexture_ = loadMetaDataTexture((basicImagePath));
		counterToClose_ = 0;
		delayCounter_ = 0;
		source_->w = destination_->w = currentTexture_.infoImage.widthFrame;
		source_->h = destination_->h = currentTexture_.infoImage.heightFrame;
		state = Close;
	}

	void setOtherDoor(Door* otherDoor)
	{
		this->otherDoor = otherDoor;
	}
	Door* getOtherDoor()
	{
		return otherDoor;
	}

	void toOpen();
	void stateMachine() override;
};