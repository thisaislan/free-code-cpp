#ifndef PERSONS_H
#define PERSONS_H

#include <iostream>

namespace persons {

	class Actor {
	public:
		enum Type { KNIGHT, ARCHER, HORSE, CAPTAIN, DELIVERYMAN, LANCER };

		static const int NUMBER_TYPES;

		Actor(std::string name, Type type) :
			attack(getAttackByType(type)),
			defense(getDefenseByType(type)),
			sprite(getSpriteByType(type)),
			name(name) {}

		int getAttack() const { return attack; }
		int getDefense()  const { return defense; }
		std::string &getSprite() const { return sprite; }
		std::string getName() const { return name; }

	protected:
		int attack;
		int defense;
		std::string &sprite;
		std::string name;

		int getAttackByType(Type type);
		int getDefenseByType(Type type);

	private:
		static std::string *sprites[];

		std::string &getSpriteByType(Type type);
	};

}

#endif // !PERSONS_H