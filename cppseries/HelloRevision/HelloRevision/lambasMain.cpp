#include<iostream>
#include<vector>
#include<functional>




void ForEach(std::vector<int> values, const std::function<void(int)>& fun) {

	for (auto x : values)
		fun(x);
}



int main() {
	std::vector<int> arr{ 1,2,3,4,5 };
	auto lambda = [](int val) {std::cout << val << std::endl; };
	ForEach(arr, lambda);
}