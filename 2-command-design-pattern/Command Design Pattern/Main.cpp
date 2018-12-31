//
//  C++ lang
//  Created by this.aislan
//  Created with Visual Studio in Windows
//

#include <iostream>

#include "Support.h"
#include "InputHandler.h"
#include "CommandActions.h"
#include "Persons.h"

using std::cout;
using std::cin;
using std::endl;

using support::System;
using handler::InputHandler;
using persons::Actor;
using commandActions::JumpCommand;
using commandActions::WalkCommand;
using commandActions::WhateverCommand;

int main() {

	char input = 'x';
	Actor *actor = new Actor();
	InputHandler inputHandler(new JumpCommand(actor), new WalkCommand(actor), new WhateverCommand(actor));

	cout << "Press \"w\" to Jump, \"a\" or \"d\" to Walk, \"x\" to exit ... and whatever to whatever!" << endl;
	cin >> input;

	while (input != 'x') {
		inputHandler.executeHandler(input);
		cin.clear();
		System::ignoreCinMax();
		cin >> input;
	}

	System::pause();
	return EXIT_SUCCESS;
}