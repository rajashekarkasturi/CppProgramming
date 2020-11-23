
#include<iostream>
#include<thread>


using namespace std;

/*
class NewClass {
    public:
        void operator()(string& msg) {
            cout << "In thread 1: " << msg << endl;
        }
};


void function_1() {
    cout << "Sample Function_1 of t1 thread" << endl;
}

void sampleThreadManipulation() {
    NewClass obj1;
    std::thread t1(obj1);     //t1 starts running
    //t1.join();  //main thread waits for t1 to finish

    //t1.detach(); //t1 will be independent from the main thread(Runs on its own) ---Daemon process

    //Once the thread is detached from the main thread, it cannot be used again by t1.join
    //to check if the thread is detached or not, we use t1.joinable()

    try {
        for(int i  = 0 ; i < 100 ; i++) 
            cout << "From main: "<< i << endl;
    } catch(...) {
        t1.join();
        throw;
    }

    //with or without exception we can join the thread t1 using wrapper calss
    //using RAII (Resource acquisition is Initialization)
    // Wrapper w(t1); so that it does not go out of scope

    //Thread object can be called using any functions(lambda, object, ...)
    t1.join();

    if(!t1.joinable())
        cout << "Detached " <<endl; 

}

void referencing_threads() {
    string s = "Hello world";
    //print ID of Parent thread
    cout<< std::this_thread::get_id() << endl;


    NewClass obj1;
    std::thread t2(obj1, std::move(s)); //the only way to pass parameter as reference in thread
    
    //To get child thread, thread ID
    cout<< t2.get_id() << endl;

    // std::thread t3 = t2 
    //Transfering ownership doesn't work properly, we need to use move function.

    std::thread t3 = std::move(t2);

    //t2.join();
    t3.join();
    //cout << "from main: " << s << endl;
}
*/

int main() {

  return 0;
}