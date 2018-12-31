#include "InputHandler.h"

#include "CommandActions.h"

namespace handler {
	
	void InputHandler::executeHandler(char input) {
		if (input == 'w') {
			jumpCommand->execute();
		} else if (input == 'a' || input == 'd') {
			walkCommand->execute();
		} else {
			whateverCommand->execute();
		}
	}

}