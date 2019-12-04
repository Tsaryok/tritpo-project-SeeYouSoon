#pragma once

#include "MainCharacter.hpp"
#include "Observer.hpp"

class MainController
{
	MainCharacter* player_;
	Observer* observer_;
public:
	void toActionTrying(int signal = 0);
	void setPlayer(MainCharacter* player);
	void setObserver(Observer* observer);
	void keyboardHandler();
};
