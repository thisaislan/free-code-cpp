#ifndef ACTIONS_H
#define ACTIONS_H

#include "Command.h"
#include "Persons.h"

namespace commandActions {

	class JumpCommand : public designPattern::Command {
	public:
		JumpCommand(persons::Actor *actor) : actor(actor) {}
		void execute() override;
	private:
		persons::Actor *actor;
	};

	class WalkCommand : public designPattern::Command {
	public:
		WalkCommand(persons::Actor *actor) : actor(actor) {}
		void execute() override;
	private:
		persons::Actor *actor;
	};

	class WhateverCommand : public designPattern::Command {
	public:
		WhateverCommand(persons::Actor *actor) : actor(actor) {}
		void execute() override;
	private:
		persons::Actor *actor;
	};

}

#endif // !ACTIONS_H