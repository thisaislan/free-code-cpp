#include "Game.h"

#include <cstdlib>
#include <string>
#include <cstdint>

#include "Support.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

using support::System;
using persons::Actor;
using factories::FlyweightFactory;

namespace game {

	Actor::Type Game::getRandomType() {
		return static_cast<Actor::Type>(rand() % Actor::NUMBER_TYPES);
	}

	void Game::gamePresent() {
		cout << "Welcome to Knight X Knight!\n\n" << endl;
		cout << "Where the best battalion warriors to defend your side!\nAre you prepared?\n\n" << endl;
	}

	FlyweightFactory::Side Game::chooseYourSide() {
		char input = 'x';

		cout << "Choose your side\n\n" << endl;

		while (input == 'x') {
			cout << "Press \"d\" para Dark Side or \"w\" to White Side:" << endl;
			cin >> input;
			cin.clear();
			System::ignoreCinMax();

			if (input != 'd' && input != 'w') {
				input = 'x';
			}
		}
		return (input == 'd') ? FlyweightFactory::Side::DARK : FlyweightFactory::Side::WHITE;
	}

	void Game::presentPlaySideAndScoreboard(FlyweightFactory::Side *playerSide,
		unsigned int *matchNumber,
		unsigned int *playerScore,
		unsigned int *cpuScore) {
		string playerSideDisplayable = (*playerSide == FlyweightFactory::Side::DARK) ? "Dark Side " : "White Side";
		cout << "--------------------------Scoreboard----------------------------" << endl;
		cout << "     Player: " << playerSideDisplayable <<
			"    Match: " << *matchNumber <<
			"      Player " << *playerScore <<
			" X " <<
			"CPU " << *cpuScore << endl;
		cout << "--------------------------Scoreboard----------------------------" << endl;
	}

	void Game::presentFistMatch() {
		cout << "Are you prepared?\n\n" << endl;
	}

	Game::RoundResult Game::makeOneRound(Actor *actorToAttack, Actor *actorToDefense, FlyweightFactory::Side *sideToAttack, FlyweightFactory::Side *playerSide) {
		bool isPlayersAttack = *sideToAttack == *playerSide;
		string attackDisplayable = (*sideToAttack == FlyweightFactory::Side::DARK) ? "Dark  Attack" : "-White Attack-";
		string bottomDisplayable;
		RoundResult roundResult;

		cout << "\n\n------------------------" << attackDisplayable << "--------------------------\n\n" << endl;

		cout << actorToAttack->getSprite() << endl;
		cout << actorToAttack->getName() << endl;

		cout << "                           Attack: " << actorToAttack->getAttack() << "\n\n" << endl;

		cout << actorToDefense->getSprite() << endl;
		cout << actorToDefense->getName() << endl;

		cout << "                          Defense: " << actorToDefense->getDefense() << "\n\n" << endl;

		if (actorToAttack->getAttack() > actorToDefense->getDefense()) {
			bottomDisplayable = "Attacker win";
			roundResult = (isPlayersAttack) ? RoundResult::PlayerVictory : RoundResult::PlayerDefeat;
		} else if (actorToAttack->getAttack() < actorToDefense->getDefense()) {
			bottomDisplayable = "-Defender win";
			roundResult = (!isPlayersAttack) ? RoundResult::PlayerVictory : RoundResult::PlayerDefeat;
		} else {
			bottomDisplayable = "-----Draw----";
			roundResult = RoundResult::Draw;
		}
		cout << "------------------------" << bottomDisplayable << "--------------------------\n\n" << endl;

		return roundResult;
	}

	void Game::calculateRound(RoundResult *roundResult, unsigned int *roundPlayerScore, unsigned int *rounCpuScore) {
		if (*roundResult == RoundResult::PlayerVictory) {
			*roundPlayerScore += 1;
		} else if (*roundResult == RoundResult::PlayerDefeat) {
			*rounCpuScore += 1;
		}
	}

	void Game::calculateMatch(unsigned int *roundPlayerScore, unsigned int *rounCpuScore, unsigned int *playerScore, unsigned int *cpuScore) {
		if (*roundPlayerScore > *rounCpuScore) {
			*playerScore += 1;
		} else if (*roundPlayerScore < *rounCpuScore) {
			*cpuScore += 1;
		}
	}

	void Game::showResultMatch(unsigned int *roundPlayerScore, unsigned int *rounCpuScore) {
		string result;

		if (*roundPlayerScore > *rounCpuScore) {
			result = " Player Win ";
		} else if (*roundPlayerScore < *rounCpuScore) {
			result = "   CPU Win  ";
		} else {
			result = "    Draw    ";
		}
		cout << "\n\n\n\n------------------------ Match result --------------------------" << endl;
		cout << "------------------------" << result << "----------------------------" << endl;
		cout << "                     Player " << *roundPlayerScore << " X " << "CPU " << *rounCpuScore << endl;
		cout << "------------------------" << result << "----------------------------\n\n" << endl;
	}

	bool Game::questionAfterMatch(unsigned int *matchNumber) {
		return (*matchNumber <= 100) ? tryAgain() : endMatchs();
	}

	bool Game::tryAgain() {
		char input = 'x';
		cout << "-------------------------- Do you want another game ? --------------------------\n" << endl;

		while (input == 'x') {
			cout << "Press \"y\" to Yes or \"n\" to Not:" << endl;
			cin >> input;
			cin.clear();
			System::ignoreCinMax();

			if (input != 'y' && input != 'n') {
				input = 'x';
			}
		}
		return (input == 'y') ? true : false;
	}

	bool Game::endMatchs() {
		cout << "\nCPU says: No more matchs for me\n" << endl;
		System::pause();
		return false;
	}

	void Game::finalMessage(unsigned int *playerScore, unsigned int *cpuScore) {
		string message = "";
		string scoreMessage = "";

		if (*playerScore > *cpuScore) {
			message = finalMessagePlayerWin();
			scoreMessage = "\n------------------------ Player Win ----------------------------";
		} else if (*playerScore < *cpuScore) {
			message = finalMessagePlayerLose();
			scoreMessage = "\n-------------------------- CPU Win -----------------------------";
		} else {
			scoreMessage = "\n--------------------------- Draw -------------------------------";
		}
		cout << scoreMessage << endl;

		message = (message != "") ? "CPU says: " + message : "\n";

		cout << message << endl;
		cout << "\n\n\n\n\n\nAll ASCII arts selected on http://ascii.co.uk/" << endl;
		cout << "Thanks for playing" << endl;
		cout << ":)\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	}

	string Game::finalMessagePlayerWin() {
		switch (rand() % 8) {
		case 0: return "Lucky beginner";			
		case 1: return "";
		case 2: return "Fleeing not to lose";			
		case 3: return "I look forward to rematch";			
		case 4: return "";			
		case 5: return "...";
		case 6: return "I'm not on a good day";			
		case 7: return "";			
		}
	}

	string Game::finalMessagePlayerLose() {
		switch (rand() % 8) {
		case 0: return "More luck in the next";
		case 1: return "";
		case 2: return "Expected result";
		case 3: return "Humans always running";
		case 4: return "Try not to cry";
		case 5: return "Are you really going to quit?";
		case 6: return "";
		case 7: return "When the next game is over, you will be baked, and then there will be cake";
		}
	}

}