#include "Observer.hpp"
#include "ObjectStorage.hpp"
#include "Values.hpp"
#include "Camera.hpp"
#include "SDL.h"

MainCharacter* Observer::player = nullptr;
vector<CollisionObject*> Observer::collisionObjects;
vector<EnemyCharacter*> Observer::enemies;
Observer::gameState Observer::gameState_ = Observer::Walk;

void Observer::toActionTrying(const int signal)
{
	if (!gameState_)
	{
		switch (signal) {
		case 0:
			player->actionTrying(MainCharacter::Static1);
			break;
		case 1:
			player->actionTrying(MainCharacter::Walk, MainCharacter::Right);
			break;
		case 2:
			player->actionTrying(MainCharacter::Walk, MainCharacter::Left);
			break;
		}
	}
	else
	{
		switch (signal) {
		case 3:
			player->actionTrying(MainCharacter::Attack1);
			break;
		case 4:
			player->actionTrying(MainCharacter::Attack2);
			break;
		case 5:
			player->actionTrying(MainCharacter::Attack3);
			break;
		}
	}
}
void Observer::toCamera()
{
	if (Observer::player->getObjectPosition().x + Observer::player->getWidthFrame() / 2 >= Values::SCREEN_WIDTH / 2 &&
		Observer::player->getObjectPosition().x + Observer::player->getWidthFrame() / 2 <=
		(MainCharacter::mapSize.width - Values::SCREEN_WIDTH / 2))
	{
		Camera::x = Observer::player->getObjectPosition().x + Observer::player->getWidthFrame() /
			2 - Values::SCREEN_WIDTH / 2;
	}
	else if (Observer::player->getObjectPosition().x - Observer::player->getWidthFrame() / 2 >
		(MainCharacter::mapSize.width - Values::SCREEN_WIDTH / 2))
	{
		Camera::x = MainCharacter::mapSize.width - Values::SCREEN_WIDTH;
	}//–ешить чЄ по высоте
}
bool Observer::checkCollision(Entity* entityA, Entity* entityB)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	int delta = 50;

	leftA = entityA->getObjectPosition().x + delta;
	rightA = entityA->getObjectPosition().x + entityA->getDestination().w - delta;
	topA = entityA->getObjectPosition().y;
	bottomA = entityA->getObjectPosition().y + entityA->getDestination().h;

	leftB = entityB->getObjectPosition().x;
	rightB = entityB->getObjectPosition().x + entityB->getDestination().w;
	topB = entityB->getObjectPosition().y;
	bottomB = entityB->getObjectPosition().y + entityB->getDestination().h;

	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	return true;
}
bool Observer::collisionDetection(Entity* entity)
{
	for (CollisionObject* object : collisionObjects)
	{
		if (checkCollision(entity, object))
		{
			return true;
		}
	}
	return false;
}
bool Observer::battleDetection()
{
	for (EnemyCharacter* enemy : enemies)
	{
		if (checkCollision(player, enemy))
		{
			gameState_ = Battle;
			return true;
		}
	}
	return false;
}