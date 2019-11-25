#include "EnemyCharacter.hpp"

void EnemyCharacter::stateMachine()
{
	if (hitPoint_ <= 0) {
		setState(Death);
	}

	if (getFrameCounter() > currentTexture_.infoImage.framesNumber)
	{
		if (getState() == Attack1 || getState() == Attack2 || getState() == Attack3)
		{
			setState(Static1);
		}
		if (getState() == Walk || getState() == Static1)
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