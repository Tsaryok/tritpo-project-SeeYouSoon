#pragma once
#include <vector>
#include "Entity.hpp"

using namespace std;

class Character : public Entity
{
private:
	int state_;

protected:
	vector<MetaDataTexture> textures_;
	Character(const int destinationX, const int destinationY) : Entity(destinationX, destinationY)
	{
		state_ = -1;
	}

	void setState(const int state);

public:
	
	int getState()
	{
		return state_;
	}
};