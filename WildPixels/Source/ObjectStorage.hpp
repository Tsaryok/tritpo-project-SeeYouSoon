#pragma once
#include <vector>
#include "Camera.hpp"
#include "Observer.hpp"
#include "Background.hpp"
#include "MainCharacter.hpp"
#include "EnemyCharacter.hpp"
#include "CollisionObject.hpp"
#include "Door.hpp"

class ObjectStorage
{
	friend class Object;
private:
	vector<Entity*> objects_;
	
public:
	ObjectStorage()
	{
		Camera::x = 0;
		Camera::y = 0;

		addCollisionObject(new CollisionObject(620, 0, CollisionObject::Wall));
		addCollisionObject(new CollisionObject(-15, 462, CollisionObject::Wall));
		addCollisionObject(new CollisionObject(-15, 492, CollisionObject::Wall));
		addCollisionObject(new CollisionObject(964, 442, CollisionObject::Wall));
		addCollisionObject(new CollisionObject(964, 492, CollisionObject::Wall));
		addCollisionObject(new CollisionObject(1890, 442, CollisionObject::Wall));
		addCollisionObject(new CollisionObject(1890, 492, CollisionObject::Wall));
		addCollisionObject(new CollisionObject(2594, 492, CollisionObject::Wall));
		addCollisionObject(new CollisionObject(2594, 184, CollisionObject::Wall));
		addCollisionObject(new CollisionObject(2594, -124, CollisionObject::Wall));
		objects_.push_back(new Background());
		

		for (int i = 0; i < objects_[1]->mapSize.width; i += 80) 
		{
			addCollisionObject(new CollisionObject(i, 800, CollisionObject::Floor));
		}

		for (int i = 680; i < objects_[1]->mapSize.width; i += 80)
		{
			addCollisionObject(new CollisionObject(i, 370, CollisionObject::Floor));
		}
		
		addDoors(new Door(1100, 48), new Door(764, 478));
		addDoors(new Door(1600, 48), new Door(1600, 478));
		addDoors(new Door(2000, 48), new Door(2000, 478));
		addEnemy(new EnemyCharacter(700, 288));
		Observer::player = new MainCharacter(150, 684);
		objects_.push_back(Observer::player);
	};

	void gameStep();

	void addCollisionObject(CollisionObject* obj);
	void addEnemy(EnemyCharacter* enemy);
	void addDoors(Door* door1, Door* door2);
};