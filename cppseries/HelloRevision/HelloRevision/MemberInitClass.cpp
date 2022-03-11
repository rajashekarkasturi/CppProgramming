#include<iostream>

class Entity {
private:
	std::string m_Name;
public:

	//These member initializations happen in the order of the initialization of the variables. This kind of helps in avoiding the multiple instantiation of variables.
	Entity()
		: m_Name("Rajashekar") 
	{

	}

	Entity(const std::string& name) 
		: m_Name(name)
	{

	}

	const std::string& GetName() const { return m_Name;  }
};

int main() {
	Entity e0;
	std::cout << e0.GetName() << std::endl;

	Entity e1("Kasturi");
	std::cout << e1.GetName() << std::endl;

	return std::cin.get();
}