#include<iostream>

class Vec2 {
public:
	float a = 0.5, b=0.5;
};

std::ostream& operator<<(std::ostream& os, const Vec2& v1) {
	os << v1.a << " " << v1.b << std::endl;
	return os;
}

int main() {
	Vec2 v1;
	std::cout << v1 << std::endl;
	std::cin.get();
}

