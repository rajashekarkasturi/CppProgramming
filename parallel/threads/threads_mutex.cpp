#include <iostream>
#include <thread>
#include <mutex>

// Our lock at global scope
std::mutex my_mutex;


//Acts as a lockguard for the mutex, to prevent uncertainity safely while executing the logic under it.
void print(int t_i)
{
    std::lock_guard<std::mutex> g(my_mutex);
    std::cout << "Thread is running from t" << t_i << '\n';
}



int main()
{
    std::thread t0(print, 0);
    std::thread t1(print, 1);
    std::thread t2(print, 2);
    std::thread t3(print, 3);

    t0.join();
    t1.join();
    t2.join();
    t3.join();

    return 0;
}