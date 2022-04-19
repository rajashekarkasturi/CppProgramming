#include<iostream>

template<typename T>
void print(T value) {
	std::cout << value << std::endl;
}

int main() {

	print(5);
	print("Hello world");
	print(5.5f);
	return 0;
}