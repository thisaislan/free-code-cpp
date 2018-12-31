#include "CommandActions.h"

namespace commandActions {

	void WalkCommand::execute() {
		actor->walk();
	}

}