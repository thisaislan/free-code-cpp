#ifndef HEROS_H
#define HEROS_H

#include <iostream>

#include "Persons.h"

namespace heros {

	class FirstHero : public persons::ActorBase {
	protected:
		void presentationAfterAttack() override;

	private:
		static const std::string *SPRITE;
	};

	class SecondHero : public persons::ActorBase {
	protected:
		void presentationAfterAttack() override;

	private:
		static const std::string *SPRITE;
	};

	class ThirdHero : public persons::ActorBase {
	protected:
		void presentationAfterAttack() override;

	private:
		static const std::string *SPRITE;
	};

}

#endif // !HEROS_H