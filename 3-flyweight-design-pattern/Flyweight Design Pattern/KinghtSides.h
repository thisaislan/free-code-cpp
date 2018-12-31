#ifndef KINGHT_SIDES_H
#define KINGHT_SIDES_H

#include "Person.h"

namespace kinghtSides {

	class WhiteSide : public persons::Actor {
	public:
		WhiteSide(Type type) : Actor(getWhiteNameByType(type), type) {}

	private:
		std::string getWhiteNameByType(Type type);
	};

	class DarkSide : public persons::Actor {
	public:
		DarkSide(Type type) : Actor(getDarkNameByType(type), type) {}

	private:
		std::string getDarkNameByType(Type type);
	};

}

#endif // !KINGHT_SIDES_H