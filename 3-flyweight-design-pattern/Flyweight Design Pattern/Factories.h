#ifndef FACTORIES_H
#define FACTORIES_H

#include "Person.h"
#include <map>

namespace factories {

	class FlyweightFactory {
	public:
		enum Side { DARK = -1, WHITE = 1 };

		static persons::Actor *getActor(Side side, persons::Actor::Type type);
		static void deleteActors();

	private:
		static std::map<int, persons::Actor*> actorsMap;
	};

}

#endif // !FACTORIES_H

