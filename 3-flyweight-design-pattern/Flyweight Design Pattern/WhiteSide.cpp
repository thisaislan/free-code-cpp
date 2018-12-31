#include "KinghtSides.h"

namespace kinghtSides {

	std::string WhiteSide::getWhiteNameByType(Type type) {
		switch (type) {
		case KNIGHT: return "                         Sword of Omens";
		case ARCHER: return "                             Shirou";
		case HORSE: return "                              Roach";
		case CAPTAIN: return "                             Artoria";
		case DELIVERYMAN: return "                             Kupo";
		case LANCER: return "                         Freya Crescent";
		}
	}

}