#include "Game.h"

#include <string>
#include <algorithm>

#include "Support.h"
#include "Heros.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::rand;
using std::random_shuffle;

using heros::FirstHero;
using heros::SecondHero;
using heros::ThirdHero;
using support::System;

namespace game {

	persons::ActorBase *Game::heros[] = {
	   new FirstHero(),
	   new SecondHero(),
	   new ThirdHero()
	};

	const string *Game::SPRITE_BAD_END = new string("                          ____\n                  __,-~~/~    `---.\n                _/_,---(      ,    )\n            __ /        <    /   )  \\___\n  ---===;;;'====------------------===;;;===----- -  -\n               \\/  ~\"~\"~\"~\"~\"~\\~\"~)~\"/\n               (_ (   \\  (     >    \\)\n                \\_( _ <         >_>'\n                   ~ `-i' ::>|--\"\n                       I;|.|.|\n          sv,s          <|i::|i|`.\n           fwf   \\ \\ (` ^'\"`-' \") / /   bs\n       sc  .,:&Hi' `'   \"' \\\\|&b  SMHo_   djww\n         oHMM  M#*}      ?    `?&dMMMMMMHo.\n      .dM MM H\"'''' .#$ / \\   ,oHH* &  9M MMM?.\n      dHH?'     \\ (` ^'\"`-' \") / M MMMM#bd#odMML\n     H' |\\                  `dMMMM MMMMMMMMM9Mk\n    JL/\"7+,.                `MMMMMM MMMMMMMMH9ML\n   -`Hp     '               |MMM MMMMMMMMM MMHH|:\n   :  \\\\#M#d?                `HMMMMMMMMMMMMMMMMH.\n   -. ,MMMMMMMM6o_                    |MMMMMMMM':\n   :  |MMMMM MMMMMMMb\\                 TMM  MMMT :\n  .    ?MMMMMMM MMMMM'                 :MMMMMM|.`\n   -    ?H MMMMMMM  :                  HMMMMM  |:\n     .    `MMM MMT''                   HMMM*''-\n      -    TMMMMM'                     MM*'  -\n       '.   HMM#                            -\n           -. `b,,    .                . '\n             '-\\   .,               .-`\n                 '-:b~\\\\_,od q==--\"\n");
	const string *Game::SPRITE_GOOD_END = new string(".    .    *  .   .  .   .  *     .  .        . .   .     .  *   .     .  .   .\n   *  .    .    *  .     .         .    * .     .  *  .    .   .   *   . .    .\n. *      .   .    .  .     .  *      .      .        .     .-o--.   .    *  .\n .  .        .     .     .      .    .     *      *   .   :O o O :      .     .\n____   *   .    .      .   .           .  .   .      .    : O. Oo;    .   .\n `. ````.---...___      .      *    .      .       .   * . `-.O-'  .     * . .\n   \\_    ;   \\`.-'```--..__.       .    .      * .     .       .     .        .\n   ,'_,-' _,-'             ``--._    .   *   .   .  .       .   *   .     .  .\n   -'  ,-'                       `-._ *     .       .   *  .           .    .\n    ,-'            _,-._            ,`-. .    .   .     .      .     *    .   .\n    '--.     _ _.._`-.  `-._        |   `_   .      *  .    .   .     .  .    .\n        ;  ,' ' _  `._`._   `.      `,-''  `-.     .    .     .    .      .  .\n     ,-'   \\    `;.   `. ;`   `._  _/\\___     `.       .    *     .    . *\n     \\      \\ ,  `-'    )        `':_  ; \\      `. . *     .        .    .    *\n      \\    _; `       ,;               __;        `. .           .   .     . .\n       '-.;        __,  `   _,-'-.--'''  \\-:        `.   *   .    .  .   *   .\n          )`-..---'   `---''              \\ `.        . .   .  .       . .  .\n        .'                                 `. `.       `  .    *   .      .  .\n       /                                     `. `.      ` *          .       .\n      /                                        `. `.     '      .   .     *\n     /                                           `. `.   _'.  .       .  .    .\n    |                                              `._\\-'  '     .        .  .\n    |                                                 `.__, \\  *     .   . *. .\n    |                                                      \\ \\.    .         .\n    |                                                       \\ \\ .     *    *\n");
	const int Game::NUMBER_OF_HERO = 3;

	void Game::prepareGame() {
		rearrangeHeros();
		chosenHero = sortHero();
	}

	void Game::rearrangeHeros() {
		random_shuffle(&heros[0], &heros[NUMBER_OF_HERO]);
	}

	int Game::sortHero() {
		return rand() % NUMBER_OF_HERO;
	}

	void Game::presentGame() {
		cout << "Once again evil threatens the earth, there are three heroes who can save us.\nBut only one of them can actually do away with evil.\n\n" << endl;
		cout << "Only you can tell who will save us ...\n" << endl;
	}

	void Game::questionHero() {
		cout << "Please choose hero 1, 2 or 3 to save us..." << endl;
		cout << "Choose wisely or will be our end:" << endl;

		do {
			if (cin.fail()) {
				cout << "Please choose wisely:" << endl;
				cin.clear();
				System::ignoreCinMax();
			} else if (selectHero > NUMBER_OF_HERO || selectHero < 0) {
				cout << "Please choose between hero 1, 2 and 3 we are running out of time:" << endl;
				cin.clear();
				System::ignoreCinMax();
			}
			cin >> selectHero;
		} while (!cin.good() || selectHero > NUMBER_OF_HERO || selectHero <= 0);
	}

	void Game::showResult() {
		(isCorrectHero()) ? showGoodResult() : showBadResult();
	}

	bool Game::isCorrectHero() {
		return chosenHero + 1 == selectHero;
	}

	void Game::showBadResult() {
		cout << *SPRITE_BAD_END << endl;
		cout << "Oh no ... This was not our hero!" << endl;
		cout << "It's the end of the earth ...\n\n" << endl;
	}

	void Game::showGoodResult() {
		heros[selectHero - 1]->attack();
		System::pauseAndClear();
		cout << *SPRITE_GOOD_END << endl;
		cout << "Thanks to your wise choice the earth will live to have a tomorrow!" << endl;
		cout << "Thank you\n\n" << endl;
	}

	bool Game::tryAgain() {
		char input = 'x';
		cout << "Would you like to use the time machine to go back in time and choose our hero again?\n" << endl;

		while (input == 'x') {
			cout << "Press \"y\" to Yes or \"n\" to No:" << endl;
			cin >> input;
			cin.clear();
			System::ignoreCinMax();

			if (input != 'y' && input != 'n') {
				input = 'x';
			}
		}
		return (input == 'y') ? true : false;
	}

	void Game::showEnd() {
		cout << "ASCII arts selected on http ://ascii.co.uk/\n" << endl;
		cout << "Characters of the original animation Dragon Ball Z" << endl;
		cout << "Created by Akira Toriyama" << endl;
		cout << "Original work Dragon Ball(1984-1995)" << endl;
		cout << "Owner Bird Studio / Shueisha" << endl;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nThanks for playing" << endl;
		cout << ":)\n\n" << endl;
	}

}