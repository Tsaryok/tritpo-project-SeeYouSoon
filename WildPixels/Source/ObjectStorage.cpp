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

void ObjectStorage::addDoors(Door* door1, Door* door2)
{
	door1->setOtherDoor(door2);
	door2->setOtherDoor(door1);

	objects_.push_back(door1);
	objects_.push_back(door2);

	Observer::doors.push_back(door1);
	Observer::doors.push_back(door2);
}
