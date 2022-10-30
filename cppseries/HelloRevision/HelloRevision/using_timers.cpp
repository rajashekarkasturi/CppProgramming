#include <iostream>
#include <chrono>
#include <thread>

struct Timer {
	
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
	{
	
		start = std::chrono::high_resolution_clock::now();
	}


	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		float ms = duration.count() * 1000.f;
		std::cout << "Time taken: " << ms << "ms" << "\n";
	}
};


void Func() {

	Timer t;

	for (int i = 0; i < 100; ++i)
		std::cout << "hELLO " << "\n";
}



int main () 
{
	//using namespace std::literals::chrono_literals;

	Func();

	//To get the convention of 1`s` we used the namespace std::literals""chrono_literals;
	//std::this_thread::sleep_for(1s);

}