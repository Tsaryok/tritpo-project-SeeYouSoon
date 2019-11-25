#include "Chest.hpp"

void Chest::stateMachine()
{
	if(isOpened)
	{
		changeSourceCoordinates();
	}
}