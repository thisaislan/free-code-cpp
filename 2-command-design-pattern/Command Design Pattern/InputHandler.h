#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Command.h"

namespace handler {

	class InputHandler {
	public:
		InputHandler(designPattern::Command *jumpCommand,
			designPattern::Command *walkCommand,
			designPattern::Command *whateverCommand) :
			jumpCommand(jumpCommand),
			walkCommand(walkCommand),
			whateverCommand(whateverCommand) {}
			
		void executeHandler(char input);

	private:
		designPattern::Command *jumpCommand;
		designPattern::Command *walkCommand;
		designPattern::Command *whateverCommand;
	};

}

#endif // !INPUT_HANDLER_H