//
//  C++ lang
//  Created by this.aislan
//  Created with Visual Studio in Windows
//  
// All ASCII arts selected on http://ascii.co.uk/
//

#include "Support.h"
#include "Person.h"
#include "Factories.h"
#include "Game.h"

using support::System;
using persons::Actor;
using factories::FlyweightFactory;
using game::Game;

int main() {

	bool inMatch = true;
	unsigned int playerScore = 0;
	unsigned int cpuScore = 0;
	unsigned int matchNumber = 0;
	FlyweightFactory::Side playerSide;

	// Class created only for presentation and mechanics of the game
	Game *game = new Game();

	// Factory to create flyweight objects
	FlyweightFactory *flyweightFactory = new FlyweightFactory();

	// Presentation

	game->gamePresent();
	System::pauseAndClear();
	playerSide = game->chooseYourSide();
	System::clear();
	game->presentPlaySideAndScoreboard(&playerSide, &matchNumber, &playerScore, &cpuScore);
	game->presentFistMatch();
	System::pauseAndClear();

	// Flyweight start inside the for

	while (inMatch) {
		matchNumber++;
		unsigned int roundPlayerScore = 0;
		unsigned int rounCpuScore = 0;
		Game::RoundResult roundResult;

		game->presentPlaySideAndScoreboard(&playerSide, &matchNumber, &playerScore, &cpuScore);

		for (int i = 0; i < 4; i++) {
			FlyweightFactory::Side sideToAttack = (i % 2 == 0) ? FlyweightFactory::Side::WHITE : FlyweightFactory::Side::DARK;
			FlyweightFactory::Side sideToDefense = (i % 2 != 0) ? FlyweightFactory::Side::WHITE : FlyweightFactory::Side::DARK;

			// Instantiating objects through the FlyweightFactory
			Actor *actorToAttack = flyweightFactory->getActor(sideToAttack, game->getRandomType());
			Actor *actorToDefense = flyweightFactory->getActor(sideToDefense, game->getRandomType());

			roundResult = game->makeOneRound(actorToAttack, actorToDefense, &sideToAttack, &playerSide);
			game->calculateRound(&roundResult, &roundPlayerScore, &rounCpuScore);
		}
		// More presentation
		game->calculateMatch(&roundPlayerScore, &rounCpuScore, &playerScore, &cpuScore);
		game->showResultMatch(&roundPlayerScore, &rounCpuScore);
		game->presentPlaySideAndScoreboard(&playerSide, &matchNumber, &playerScore, &cpuScore);
		System::pause();
		inMatch = game->questionAfterMatch(&matchNumber);		
		System::clear();
	}
	// Deleting all objects from the FlyweightFactory
	flyweightFactory->deleteActors();

	// More more presentation
	game->presentPlaySideAndScoreboard(&playerSide, &matchNumber, &playerScore, &cpuScore);
	game->finalMessage(&playerScore, &cpuScore);

	System::pause();
	return EXIT_SUCCESS;
}