#pragma once
#include "Character.hpp"

using namespace std;

class EnemyCharacter : public Character
{
private:
	int hitPoint_;
	int maxHitPoint_;

public:
	enum Actions
	{
		Static1,
		Walk,
		Attack1,
		Attack2,
		Attack3,
		Death,
		NumberOfActions
	};

	EnemyCharacter() = delete;
	EnemyCharacter(int destinationX, int destinationY) : Character(destinationX, destinationY)
	{
		hitPoint_ = 20;
		maxHitPoint_ = 20;
		vector<string> actionName = { "static_1", "walk", "attack_1", "attack_2", "attack_3", "death" };
		const char* basicImagesPath = "Resource\\images\\EnemyCharacter\\";
		const char* basicEffectsPath = "Resource\\sound\\EnemyCharacter\\";

		for (int i = 0; i < NumberOfActions; i++)
		{
			textures_.push_back(loadMetaDataTexture((basicImagesPath + actionName[i])));
			effects_.push_back(loadEffect(basicEffectsPath + actionName[i]));
		}
		setState(Static1);
		setOrientation(Left);
	}

	void stateMachine() override;

	void toDamage(int damage) { hitPoint_ -= damage; }
	void toHeal(const int heal)
	{
		if ((hitPoint_ += heal) > maxHitPoint_)
		{
			hitPoint_ = maxHitPoint_;
		}
	}
	void setMaxHitPoint(const int maxHitPoint) { maxHitPoint_ = maxHitPoint; }
	int getMaxHitPoint() const { return maxHitPoint_; }
};