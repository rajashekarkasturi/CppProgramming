#include<iostream>

int main() {


	char ch;
	char* chptr;

	std::cout << "64-bit system" << std::endl;
	std::cout << "Size of char and char*" << std::endl;
	std::cout << sizeof(ch) << " " << sizeof(chptr) << std::endl;

	std::cout << "Size of short " << std::endl;
	std::cout << sizeof(short) << std::endl;

	std::cout << "Size of int and int*" << std::endl;
	std::cout << sizeof(int) << " " << sizeof(int*) << std::endl;
	//				4					8

	std::cout << "Size of double and double* " << std::endl;
	std::cout << sizeof(double) <<" " << sizeof(double*) << std::endl;


	std::cout << "Size of void*" << std::endl;
	std::cout << sizeof(void*) << std::endl;

 	
	std::cout << "Hello Qcom!" << std::endl;
}