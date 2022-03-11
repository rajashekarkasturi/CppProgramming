#include<iostream>

class Entity {
private:
	std::string m_Name;
public:
	Entity(): m_Name("default") {	}
	Entity(const std::string& name)
		: m_Name(name){	}

	const std::string& get_Name() const {
		return m_Name;
	}
};

int main() {

	Entity* ptr;
	{
		Entity* e = new Entity("Rajashekar");
		ptr = e;
		std::cout << e->get_Name() << std::endl;
	}

	std::cin.get();
	delete e;
}