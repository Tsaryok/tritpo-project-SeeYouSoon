#include "Character.hpp"


void Character::setState(const int state)
{
	if (this->state_ != state)
	{
		Mix_HaltChannel(2);
		currentEffect_ = effects_[state];
		this->state_ = state;
		currentTexture_ = textures_[state];
		delayCounter_ = 0;
		source_->w = destination_->w = currentTexture_.infoImage.widthFrame;
		source_->h = destination_->h = currentTexture_.infoImage.heightFrame;
		beginAnimationsCycle();
	}
}