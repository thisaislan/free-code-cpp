#ifndef PEROSN_H
#define PEROSN_H

#include <iostream>

namespace persons {

	class ActorBase {
	public:
		void attack();

	protected:
		virtual void presentationAfterAttack() = 0;

	private:
		static const std::string *SPRITES[];
		static const int NUMBER_OF_SPRITES;

		static int getTimeToAnimation(int frame);
	};

}

#endif // !PEROSN_H