#include<iostream>
#include "Log.h"


void Log(const char* message) {
	std::cout << message << std::endl;
}

int main() {
	
	int a = 10;
	a++;
	const char* string = "Hello";

	for (int i = 0; i < 5; i++) {
		const char c = string[i];
		std::cout << c << std::endl;
	}


	Log("Hello World!");
}