#include "Persons.h"

#include <iostream>

using std::cout;
using std::endl;
using std::rand;

namespace persons {

	void Actor::jump() {
		switch (rand() % 4) {
		case 0:
			cout << "I start to think I'm a frog ..." << endl;
			break;
		case 1:
			cout << "I'm a little tired, but I can still jump!" << endl;
			break;
		case 2:
			cout << "Jump" << endl;
			break;
		case 3:
			cout << "Jumping..." << endl;
			break;
		}
	}

	void Actor::walk() {
		switch (rand() % 8) {
		case 0:
			cout << "Walk" << endl;
			break;
		case 1:
			cout << "Walking..." << endl;
			break;
		case 2:
			cout << "Very walking..." << endl;
			break;
		case 3:
			cout << "Very very walking..." << endl;
			break;
		case 4:
			cout << "Are not you tired of it?" << endl;
			break;
		case 5:
			cout << "Guess what!! Walking... :(" << endl;
			break;
		case 6:
			cout << "Ok ok, I'm crawling around!" << endl;
			break;
		case 7:
			cout << "Walking is for the weak ... running now!" << endl;
			break;
		}
	}

	void Actor::whatever() {
		switch (rand() % 8) {
		case 0:
			cout << "Whatever" << endl;
			break;
		case 1:
			cout << "Attacking the enemy ... aaaaa" << endl;
			break;
		case 2:
			cout << "Fleeing from the enemy ... aaaaaaaaaaa" << endl;
			break;
		case 3:
			cout << "Hiding like a baby" << endl;
			break;
		case 4:
			cout << "I want to Jump!" << endl;
			break;
		case 5:
			cout << "Nothing!" << endl;
			break;
		case 6:
			cout << "Try again!" << endl;
			break;
		case 7:
			cout << "Tired" << endl;
			break;
		}
	}

}