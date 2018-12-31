#include "Factories.h"

#include "KinghtSides.h"

using std::map;
using std::make_pair;

using persons::Actor;
using kinghtSides::DarkSide;
using kinghtSides::WhiteSide;

namespace factories {

	std::map<int, persons::Actor*> FlyweightFactory::actorsMap;

	Actor *FlyweightFactory::getActor(Side side, Actor::Type type) {
		int key = (type + 1) * side;

		if (actorsMap.find(key) == actorsMap.end()) {
			Actor *actorToInsert;

			if (side == Side::DARK) {
				actorToInsert = new DarkSide(type);
			} else {
				actorToInsert = new WhiteSide(type);
			}
			actorsMap.insert(make_pair(key, actorToInsert));
			return actorToInsert;
		}
		return actorsMap.at(key);
	}

	void FlyweightFactory::deleteActors() {

		for (auto const &it : actorsMap) {
			delete it.second;
		}
		actorsMap.clear();
	}

}
