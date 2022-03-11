#include<iostream>
#include<string>
#include <memory>

class Entity {
public:
	Entity() {
		std::cout << "Created Entity" << std::endl;
	}

	~Entity() {
		std::cout << "Destructed Entity" << std::endl;
	}
};

int main() {
	

	//Unique Pointers
	{
		//we need to explicity call the constructor
		//std::unique_ptr<Entity> e1(new Entity());

		//Inorder to be exception safe we need to call in the following way
		//std::unique_ptr<Entity> e2 = std::make_unique<Entity>();

	}

	//Shared Pointers
	{
		std::shared_ptr<Entity> e3 = std::make_shared<Entity>();

		std::cout << "Number of references = " << e3.use_count() << std::endl;

		std::shared_ptr<Entity> e4 = e3;
		std::cout << "Number of references = " << e3.use_count() << std::endl;

		e3.reset();
		std::cout << "Number of references = " << e4.use_count() << std::endl;

		e4.reset();
	}

	std::cin.get();
}