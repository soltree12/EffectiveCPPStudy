#include <iostream>
#include <string>
#include <map>

class Monster {
public:
	virtual void showName() = 0;
};

class Goblin : public Monster {
	void showName() {
		std::cout << "고블린 생성" << std::endl;
	}
};

class Ghost : public Monster {
	void showName() {
		std::cout << "유령 생성" << std::endl;
	}
};

class MonMgr {
public:
	void newMonster(const std::string& name) {
		Monster *pMon = createMonster();
		ObjPool_[name] = pMon;
		pMon->showName();
	}
	virtual Monster* createMonster() = 0;

private:
	std::map<std::string, Monster *> ObjPool_;
};

class GoblinMgr : public MonMgr {
	Monster* createMonster() {
		return new Goblin;
	}
};

class GhostMgr : public MonMgr {
	Monster* createMonster() {
		return new Ghost;
	}
};

int main()
{
	GoblinMgr goblin;
	goblin.newMonster("goblin");
	GhostMgr ghost;
	ghost.newMonster("ghost");
}