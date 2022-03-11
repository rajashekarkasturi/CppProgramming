#include<iostream>

class Entity {
private:
	std::string m_Name;
public:
	Entity() : m_Name("default") {	}
	Entity(const std::string& name)
		: m_Name(name) {	}

	const std::string& get_Name() const {
		return m_Name;
	}
};

int main() {

	Entity* e = new Entity();
	//This way it creates memory and explicitly call the Entity constructor

	//whereas->this kind of memory allocation does not call the constructor instead allocates the size and returns an address.
	Entity* e = (Entity*)malloc(sizeof(Entity));


	//we need to delete expicitly.
	delete e; //Here delete also calls the destructor.
	//and also calls the C function free(e).

	std::cin.get();
}