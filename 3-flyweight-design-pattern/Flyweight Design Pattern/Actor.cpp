#include "Person.h"

using std::string;

namespace persons {

	int const Actor::NUMBER_TYPES = 6;
	
	string *Actor::sprites[] = {
		new string("                              ,\n                             ~O\n                           /~()'-{---\n                            /~)\n                            ~ ~"),
		new string("                                 k\n                               O  |\n                             ()Y==o\n                              /_\\ |\n                              _W_ |"),
		new string("                                  ,\n                             ____/~\\\n                         ,;~( )_  )''\n                            )/  |(\n                            ~    ~ "),
		new string("                           |\n                           + \\\n                           \\\\.G_.*=.\n                            `(H'/.\\|\n                             .>' (_--.\n                          _=/d   ,^\\\n                         ~~ \\)-'   '\n                            / |\n                           '  '"),
		new string("                                    ,_\n                               ()  /(.\\\n                              /\\__/_/\ ,)\n                          _,-((-'` /\n                         /(   d    )\n                         ` \\ /`'--\\\\\n                            ))     ))\n                           //      ^\n                           ^"),
		new string("                              ,\\\n                              ~O  ,\n                             /~;'}========\n                         ~( ))  )''\n                          )/ ~|(\n                          ~    ~")
	};

	int Actor::getAttackByType(Type type) {
		switch (type) {
		case KNIGHT: return 15;
		case ARCHER: return 8;
		case HORSE: return 0;
		case CAPTAIN: return 20;
		case DELIVERYMAN: return 5;
		case LANCER: return 18;
		}
	}

	int Actor::getDefenseByType(Type type) {
		switch (type) {
		case KNIGHT: return 15;
		case ARCHER: return 5;
		case HORSE: return 7;
		case CAPTAIN: return 10;
		case DELIVERYMAN: return 9;
		case LANCER: return 20;
		}
	}

	string &Actor::getSpriteByType(Type type) {
		return *sprites[type];
	}

}