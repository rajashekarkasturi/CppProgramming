#include<iostream>
#include<array>

int main() {
	//static creation of array
		static const int size = 5;
		int arr_static[size];
		//since we need to know array size at compile time, we need to declared it as static
	

	//Heap allocation of array
		int* arrheap = new int[10];

	//Modern c++ style of creating array, using std::array
		std::array<int, 5> modern_array;
		//Has bounce checkings
		//size checkings ........

	return 0;
}