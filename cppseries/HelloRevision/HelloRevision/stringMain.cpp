#include<iostream>
#include<string>
#include <stdlib.h>
int main() {

	const char* name = u8"name";	//1byte

	//wide character
	const wchar_t* name2 = L"rajashekar";

	//C++11 introduces
	const char16_t* name3 = u"raj";	//2bytes
	const char32_t* name4 = U"raja";	//4bytes

	//C++14: String literals
	using namespace std::string_literals;
	
	std::string name5 = "rajashekar"s + " kasturi";
	std::cout << name5 << std::endl;

	//Inorder to escape characters
	const char* example = R"(Hello
world
this
is
rajashekar)";

	std::cout << example << std::endl;


	std::cin.get();

}