#include<iostream>

int main() {

	//Dynamic
	char* buffer = new char[8];
	//fill the buffer with value zero(here) till the size specified.
	memset(buffer, 0, 8);
	
	delete[] buffer;

	//References are aliases
	
	
	
	/* -----static----
	int var = 4;
	void* ptr = &var;
	*/

	std::cin.get();
}