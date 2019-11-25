#pragma once
#include "Character.hpp"
#include <string>

using namespace std;

class MainCharacter final : public Character
{
private:
	int hitPoint_;
	int maxHitPoint_;
	
public:
	enum Actions
	{
		Static1,//без боя 
		Static2,//после боя
		Walk,
		Attack1,
		Attack2,//ПодумОть
		Attack3,
		Death,
		NumberOfActions
	};

	MainCharacter() = delete;
	MainCharacter(int destinationX, int destinationY) : Character(destinationX, destinationY)
	{
		hitPoint_ = 20;
		maxHitPoint_ = 20;
		vector<string> actionName = { "static_1", "static_2", "walk", "attack_1", "attack_2", "attack_3", "death" };
		const char* basicImagesPath = "Resource\\images\\MainCharacter\\";
		const char* basicEffectsPath = "Resource\\sound\\MainCharacter\\";

		for (int i = 0; i < NumberOfActions; i++)
		{
			textures_.push_back(loadMetaDataTexture((basicImagesPath + actionName[i])));
			effects_.push_back(loadEffect(basicEffectsPath + actionName[i]));
		}
		setState(Static1);
	}
	void actionTrying(int state, int orientation = 0);

	void stateMachine() override;

	int getWidthFrame()
	{
		return currentTexture_.infoImage.widthFrame;
	}
	int getHeightFrame()
	{
		return currentTexture_.infoImage.heightFrame;
	}
	void toDamage(int damage){ hitPoint_ -= damage; }
	void toHeal(const int heal)
	{
		if((hitPoint_ += heal) > maxHitPoint_)
		{
			hitPoint_ = maxHitPoint_;
		}
	}
	void setMaxHitPoint(const int maxHitPoint){ maxHitPoint_ = maxHitPoint; }
	int getMaxHitPoint() const{ return maxHitPoint_; }

};