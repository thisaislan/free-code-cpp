#include "CommandActions.h"

namespace commandActions {

	void JumpCommand::execute() {
		actor->jump();
	}

}