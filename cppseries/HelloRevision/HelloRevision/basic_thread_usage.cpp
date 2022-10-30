#include <iostream>
#include <thread>

static bool s_Finished = false;


void print() {

	using namespace std::literals::chrono_literals;

	std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;

	while (!s_Finished) {
		std::cout << " Thread t1 is running..." << std::endl;
		std::this_thread::sleep_for(1s);
	}

}


int main(void) {

	std::thread t1(print);

	std::cin.get();
	s_Finished = true;

	//Waits untill the t1's work is finished....
	t1.join();

	std::cout << "The Printing finished !!" << std::endl;

	return 0;
}
