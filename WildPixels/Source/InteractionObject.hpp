#pragma once
#include "Object.hpp"

class InteractionObject : public Object
{
protected:
	int state;
public:
	InteractionObject() = delete;
	InteractionObject(const int destinationX, const int destinationY) : Object(destinationX, destinationY)
	{
		
	}
};
