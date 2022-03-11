#include <iostream>


class Entity {
private:
	int m_a, m_b;
	mutable int a = 10;	// can change contents even in const methods/functions.
public:
	int get() const {
		//cannot chance the contents of the variables in this method.
		//m_a = 5; --> error

		a = 20;	//Possible, because a is mutable.
	}

	void set() {

	}
};


int main() {
	
	const int MAX_AGE = 99;
	//MAX_AGE = 20; here is a is read-only.

	int* a = new int;
	//const int* a = new int ; //contents cannot be modified
	//int const* a = new int; //contents cannot be modified.
	//int* const a = new int; //Refernce cannot be modified


	*a = 2;
	a = (int*)&MAX_AGE;
	//std::cout << *a << std::endl;

	//using Mutable in lamda

	int x = 8;
	//specify the capture, = (by value), & (by reference), using the mutable keyword to specify the value of x so that it can be modified.
	auto f = [=]() mutable {
		x++;
		std::cout << x << std::endl;
	};
	f();
	std::cout << x << std::endl;

	std::cin.get();
}