#pragma once
#include "Entity.hpp"

class Object : public Entity
{
protected:
	Object(const int destinationX, const int destinationY) : Entity(destinationX, destinationY)
	{

	}
};