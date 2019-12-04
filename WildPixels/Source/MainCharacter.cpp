#include "MainCharacter.hpp"
#include "Observer.hpp"

void MainCharacter::actionTrying(int state, int orientation )
{
	if (getState() == Attack1 || getState() == Attack2 || getState() == Attack3)
	{
		if (getFrameCounter() == currentTexture_.infoImage.framesNumber)
		{
			setState(state);
			setOrientation(orientation);
		}
	}
	else
	{
		if (getState() != Death)
		{
			setState(state);
			setOrientation(orientation);
		}
	}
}

void MainCharacter::stateMachine()
{
	if (hitPoint_ <= 0) {
		setState(Death);
	}

	if (getFrameCounter() > currentTexture_.infoImage.framesNumber)
	{
		if (getState() == Attack1 || getState() == Attack2 || getState() == Attack3)
		{
			setState(Static2);
		}
		if (getState() == Walk || getState() == Static1 || getState() == Static2)
		{
			beginAnimationsCycle();
		}
	}
	else
	{
		changeSourceCoordinates();
		changeDestinationCoordinates();
	}	
}

void MainCharacter::goThroughDoor(Door* door)
{
	setObjectPosition(door->getObjectPosition().x + (door->getDestination().w - destination_->w) / 2,
		door->getObjectPosition().y + (door->getDestination().h - destination_->h));
}