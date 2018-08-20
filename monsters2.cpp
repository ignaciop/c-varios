#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

enum MonsterType {
	DRAGON,
	GOBLIN,
	OGRE,
	ORC,
	SKELETON,
	TROLL,
	VAMPIRE,
	ZOMBIE,
	MAX_MONSTER_TYPE
};

class Monster {
public:
	enum MonsterType {
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPE
	};
	
private:
	MonsterType m_type;
	std::string m_name;
	std::string m_roar;
	int m_hitPoints;
	
public:
	Monster(MonsterType type, std::string name, std::string roar, int hitPoints)
	 : m_type(type), m_name(name), m_roar(roar), m_hitPoints(hitPoints) {}
	
	std::string getTypeString() {
		switch (m_type) {
			case DRAGON: return "dragon"; break;
			case GOBLIN: return "goblin"; break;
			case OGRE: return "ogre"; break;
			case ORC: return "orc"; break;
			case SKELETON: return "skeleton"; break;
			case TROLL: return "troll"; break;
			case VAMPIRE: return "vampire"; break;
			case ZOMBIE: return "zombie"; break;
			case MAX_MONSTER_TYPE: return " "; break;
		}
		
		return "???";
	}
	
	void print() {
		std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
	}
};

class MonsterGenerator {
public:
	static Monster generateMonster() {
		Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPE - 1));
		
		int hitPoints = getRandomNumber(1, 100);
		
		static std::string s_names[6]{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
		static std::string s_roars[6]{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*" };
		
		return Monster(type, s_names[getRandomNumber(0, 5)], s_roars[getRandomNumber(0, 5)], hitPoints);
	}
	
	static int getRandomNumber(int min, int max) {
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
		
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
};


int main() {
	srand(static_cast<unsigned int>(time(0)));
	rand();
	
	Monster m = MonsterGenerator::generateMonster();
	m.print();
	
	return 0;
}