#include<iostream>
#include <future>


using namespace std;

int AddOne(std::future<int>& f) {
    
    int N = f.get();
    cout << "Result is: " << N+1 << endl;

    return N;
}

int main() {
    int x;

    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::future<int> future1 = std::async(std::launch::async, AddOne, std::ref(f));
    
    p.set_value(4);

    x = future1.get();
    cout << "Get the value from the child " << x << endl;
    return 1;
}