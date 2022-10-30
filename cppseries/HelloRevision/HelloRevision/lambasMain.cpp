#include<iostream>
#include<vector>
#include<functional>




void ForEach(std::vector<int> values, const std::function<void(int)>& fun) {

	for (auto x : values)
		fun(x);
}



int main() {
	std::vector<int> arr{ 1,2,4, 3, 5 };

	auto it = std::find_if(arr.begin(), arr.end(), [](int value) {return value > 3;  });

	std::cout << *it << std::endl;

	//int a = 5;



	//auto lambda = [=](int val) {std::cout << val  << " " << a << std::endl; };
	
	//ForEach(arr, lambda);
}

