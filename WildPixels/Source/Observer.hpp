#pragma once
#include "MainCharacter.hpp"
#include "EnemyCharacter.hpp"
#include "CollisionObject.hpp"
#include "Door.hpp"

class Observer
{
	static enum gameState
	{
		Walk,
		Battle
	}gameState_;
public:
	static MainCharacter* player;
	static vector<CollisionObject*> collisionObjects;
	static vector<Door*> doors;
	static vector<EnemyCharacter*> enemies;
	static void toActionTrying(int signal = 0);
	static void toCamera();
	static bool checkCollision(Entity* entity1, Entity* entity2);
	static bool collisionDetection(Entity* entity);
	static bool battleDetection();
};