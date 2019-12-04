/*#include "MainController.hpp"
#include "Observer.hpp"

void MainController::toActionTrying(const int signal)
{
	if (!observer_->getGameState())
	{
		switch (signal) {
		case 0:
			player_->actionTrying(MainCharacter::Static1);
			break;
		case 1:
			player_->actionTrying(MainCharacter::Walk, MainCharacter::Right);
			break;
		case 2:
			player_->actionTrying(MainCharacter::Walk, MainCharacter::Left);
			break;
		}
	}
	else
	{
		switch (signal) {
		case 3:
			player_->actionTrying(MainCharacter::Attack1);
			break;
		case 4:
			player_->actionTrying(MainCharacter::Attack2);
			break;
		case 5:
			player_->actionTrying(MainCharacter::Attack3);
			break;
		}
	}
}

void MainController::setPlayer(MainCharacter* player)
{
	this->player_ = player;
}

void MainController::setObserver(Observer* observer)
{
	this->observer_ = observer;
}

void MainController::keyboardHandler()
{
	SDL_Event kEvent;

	while (SDL_PollEvent(&kEvent) != 0)
	{
		if (kEvent.type == SDL_KEYDOWN)
		{
			switch (kEvent.key.keysym.sym) {
			case SDLK_d:
				toActionTrying(MainCharacter::Right);
				break;
			case SDLK_a:
				toActionTrying(MainCharacter::Left);
				break;
			case SDLK_j:
				toActionTrying(MainCharacter::Attack1);
				break;
			case SDLK_k:
				toActionTrying(MainCharacter::Attack2);
				break;
			case SDLK_l:
				toActionTrying(MainCharacter::Attack3);
				break;
			}
		}
		if (kEvent.type == SDL_KEYUP)
		{
			toActionTrying();
		}
	}
}*/