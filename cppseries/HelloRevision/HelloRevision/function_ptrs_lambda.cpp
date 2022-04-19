#include<iostream>
#include<vector>
#include<functional>


void ForEach(std::vector<int> values, void(*fun)(int)) {
	
	for(auto x : values)
		fun(x);
}

//


int main() {
	std::vector<int> arr{ 1,2,3,4,5 };
	ForEach(arr, [](int value) {  std::cout << value << ",";  });
}