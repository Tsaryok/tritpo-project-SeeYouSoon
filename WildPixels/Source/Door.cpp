#include "Door.hpp"

void Door::toOpen()
{
	state = Open;
	otherDoor->state = Open;
}
void Door::stateMachine()
{
	if (state)
	{
		if (frameCounter_ == currentTexture_.infoImage.framesNumber)
		{
			if (!counterToClose_)
			{
				counterToClose_++;
			}
			else
			{
				if (counterToClose_++ == currentTexture_.infoImage.frequencyDivider * 10)
				{
					frameCounter_ = 1;
					state = Close;
					source_->x = 0;
					source_->y = 0;
					counterToClose_ = 0;
				}
			}
		}
		else
		{
			changeSourceCoordinates();
		}
	}
}