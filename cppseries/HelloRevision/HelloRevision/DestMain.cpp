#include<iostream>

class Entity {
public:
	float X, Y;

	Entity() {
		X = 0.0f;
		Y = 0.0f;
		std::cout << "Constructed Entity" << std::endl;
	}

	Entity(float x, float y) {
		X = x;
		Y = y;
	}
	~Entity() {
		std::cout << "Destructed Entity" << std::endl;
	}

	void Print() {
		std::cout << "X: " << X << " Y: " << Y << std::endl;
	}
};


void function() {

	//stack allocated memory
	Entity e1;
	e1.Print();
	e1.~Entity();

}

int main() {
	//Use new operator for Heap allocated.
	function();
	return 0;
}