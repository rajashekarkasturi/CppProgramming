#include<iostream>
#include<string>

class Entity {
private:
	std::string m_Name;
	int age;
public:
	Entity(const std::string& name)
		: m_Name(name), age(-1) {	}

	explicit Entity(int age)
		: m_Name("kasturi"), age(age) {	}

	const std::string& get_Name() const {
		return m_Name;
	}
};



int main() {

	//Entity e1 = 22;	//Implicit conversion
	Entity e2 = std::string("Rajashekar");

	Entity e3(22);
	std::cin.get();
}