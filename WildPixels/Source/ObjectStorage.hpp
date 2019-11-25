#pragma once
#include <vector>
#include "Camera.hpp"
#include "Observer.hpp"
#include "Background.hpp"
#include "MainCharacter.hpp"
#include "EnemyCharacter.hpp"
#include "CollisionObject.hpp"

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
		objects_.clear();
		Observer::collisionObjects.clear();
		objects_.push_back(new Background());
		addCollisionObject(new CollisionObject(0, 0, CollisionObject::Wall));
		addCollisionObject(new CollisionObject(0, 304, CollisionObject::Wall));
		addCollisionObject(new CollisionObject(906, 0, CollisionObject::Wall));
		addCollisionObject(new CollisionObject(906, 304, CollisionObject::Wall));
		addCollisionObject(new CollisionObject(0, 396, CollisionObject::Floor));
		addCollisionObject(new CollisionObject(80, 396, CollisionObject::Floor));
		addCollisionObject(new CollisionObject(160, 396, CollisionObject::Floor));
		addCollisionObject(new CollisionObject(240, 396, CollisionObject::Floor));
		addCollisionObject(new CollisionObject(320, 396, CollisionObject::Floor));
		addCollisionObject(new CollisionObject(400, 396, CollisionObject::Floor));
		addCollisionObject(new CollisionObject(480, 396, CollisionObject::Floor));
		addCollisionObject(new CollisionObject(560, 396, CollisionObject::Floor));
		addCollisionObject(new CollisionObject(640, 396, CollisionObject::Floor));
		addCollisionObject(new CollisionObject(720, 396, CollisionObject::Floor));
		addCollisionObject(new CollisionObject(800, 396, CollisionObject::Floor));
		addCollisionObject(new CollisionObject(880, 396, CollisionObject::Floor));
		addEnemy(new EnemyCharacter(700, 288));
		Observer::player = new MainCharacter(150, 280);
		objects_.push_back(Observer::player);
	};

	void gameStep();

	void addCollisionObject(CollisionObject* obj);
	void addEnemy(EnemyCharacter* enemy);
};