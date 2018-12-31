#ifndef GAME_H

#include <iostream>

#include "Persons.h"

namespace game {

	class Game {
	public:
		void prepareGame();
		void presentGame();
		void questionHero();
		void showResult();
		bool tryAgain();
		void showEnd();

	private:
		static persons::ActorBase *heros[];

		static const std::string *SPRITE_BAD_END;
		static const std::string *SPRITE_GOOD_END;
		static const int NUMBER_OF_HERO;

		int chosenHero = 0;
		int selectHero = 0;

		void rearrangeHeros();
		int sortHero();
		bool isCorrectHero();
		void showBadResult();
		void showGoodResult();
	};

}

#endif // !GAME_H