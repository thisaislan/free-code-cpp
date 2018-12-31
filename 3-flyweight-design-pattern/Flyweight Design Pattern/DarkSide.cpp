#include "KinghtSides.h"

namespace kinghtSides {

	std::string DarkSide::getDarkNameByType(Type type) {
		switch (type) {
		case KNIGHT: return "                         Blades of chaos";
		case ARCHER: return "                           Gilgamesh";
		case HORSE: return "                            Famine";
		case CAPTAIN: return "                             Dock";
		case DELIVERYMAN: return "                            Kyubey";
		case LANCER: return "                       Burakku Rei Ransa";
		}
	}

}