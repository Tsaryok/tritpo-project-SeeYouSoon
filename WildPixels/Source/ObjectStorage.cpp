#include "ObjectStorage.hpp"

void ObjectStorage::gameStep()
{
	for (Entity* object : objects_)
	{

		object->stateMachine();
		object->toRender();
	}
}

void ObjectStorage::addCollisionObject(CollisionObject* obj)
{
	objects_.push_back(obj);
	Observer::collisionObjects.push_back(obj);
}

void ObjectStorage::addEnemy(EnemyCharacter* enemy)
{
	objects_.push_back(enemy);
	Observer::enemies.push_back(enemy);
}