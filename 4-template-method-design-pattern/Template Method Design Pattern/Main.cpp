//
//  C++ lang
//  Created by this.aislan
//  Created with Visual Studio in Windows
//
//  ASCII arts selected on http ://ascii.co.uk/
//
//  Characters of the original animation Dragon Ball Z
//  Created by Akira Toriyama
//  Original work Dragon Ball(1984–1995)
//  Owner Bird Studio / Shueisha


#include "Support.h"
#include "Game.h"

using support::System;
using game::Game;

int main() {
	bool inGame = true;

	//The template design pattern is applied to the ActorBase class and its children, which are used by the Game class
	Game *game = new Game();

	do {
		game->prepareGame();
		game->presentGame();
		System::pauseAndClear();
		game->questionHero();
		System::pauseAndClear();
		game->showResult();
		System::pauseAndClear();
		inGame = game->tryAgain();
		System::clear();
	} while (inGame);

	game->showEnd();

	System::pause();
	return EXIT_SUCCESS;
}