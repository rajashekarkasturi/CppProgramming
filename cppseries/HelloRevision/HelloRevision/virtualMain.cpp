#include<iostream>

class Entity {
public:
	virtual std::string GetName() { return "Entity"; }
};

class Player : public Entity {
private:
	std::string m_Name;
public:
	Player(const std::string& name): m_Name(name) {	}

	std::string GetName() override { return m_Name; }
};

void print(Entity* p) {
	std::cout << p->GetName() << std::endl;
}

int main(void) {
	Entity* e = new Entity();
	print(e);

	Player* p = new Player("Rajashekar");
	print(p);
	return 0;
}