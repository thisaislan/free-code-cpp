#ifndef GAME_H

#include <iostream>

#include "Person.h"
#include "Factories.h"

namespace game {

	class Game {
	public:
		enum RoundResult { PlayerVictory, PlayerDefeat, Draw };

		persons::Actor::Type getRandomType();
		void gamePresent();
		factories::FlyweightFactory::Side chooseYourSide();

		void presentPlaySideAndScoreboard(factories::FlyweightFactory::Side *playerSide,
			unsigned int *matchNumber,
			unsigned int *playerScore,
			unsigned int *cpuScore);

		void presentFistMatch();

		RoundResult makeOneRound(persons::Actor *actorToAttack,
			persons::Actor *actorToDefense,
			factories::FlyweightFactory::Side *sideToAttack,
			factories::FlyweightFactory::Side *playerSide);

		void calculateRound(RoundResult *roundResult,
			unsigned int *roundPlayerScore,
			unsigned int *rounCpuScore);

		void calculateMatch(unsigned int *roundPlayerScore,
			unsigned int *rounCpuScore,
			unsigned int *playerScore,
			unsigned int *cpuScore);

		void showResultMatch(unsigned int *roundPlayerScore, unsigned int *rounCpuScore);
		bool questionAfterMatch(unsigned int *matchNumber);
		void finalMessage(unsigned int *playerScore, unsigned int *cpuScore);

	private:
		bool tryAgain();
		bool endMatchs();
		std::string finalMessagePlayerWin();
		std::string finalMessagePlayerLose();

	};

}

#endif // !GAME_H

