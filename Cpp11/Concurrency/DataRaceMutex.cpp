
#include<iostream>
#include<mutex>
#include<thread>


using namespace std;
std::mutex mutex1;
std::mutex mutex2;

void shared_cout_anothertype() {
  //what if the cout has error in share_cout function. The mutex will be forever locked
  std::lock_guard<std::mutex> guard(mutex2); //RAII(Resource acqusition is initialization)

  //Even though cout can be accessed through other ways. One more safer way is to use ofstream and lock the stream itself

}

void shared_cout(string msg , int count) {

  //here the shared resource cout is synchronized with mutex
  mutex1.lock();
  cout << msg << count << endl;
  mutex1.unlock();
}


/*
void f1() {
  for(int i = 6 ; i  <11 ; i++) {
    cout << "from thread 1: " << i << endl;
  }
}
*/

void f2() {
  for(int i = 6 ; i  <11 ; i++) {
    shared_cout(string("from thread t2: "), i);
  }
}


/*
void raceCondition() {
  
  std::thread t1(f1);

  for(int i = 1 ; i < 5 ; i++ ) {
    cout << "from main thread: " << i  << endl;
  }
  t1.join();  
  
  //Here the both the threads main and t1 are commonly sharing cout. That is why race is occured.
  //from main thread: from thread 1: 16
  //from main thread: 2
  //from main thread: 3
  //from main thread: 4

  //from thread 1: 7
  //from thread 1: 8
  //from thread 1: 9
  //from thread 1: 10
}
*/

void NonRaceCondition() {
  std::thread t2(f2);

  for(int i = 1 ; i < 5 ; i++ ) {
    shared_cout(string("from thread main: "), i);
  }
  t2.join();

  /*---Output---
from thread main: 1
from thread main: 2
from thread main: 3
from thread main: 4
from thread t2: 6
from thread t2: 7
from thread t2: 8
from thread t2: 9
from thread t2: 10  
  */   
}

int main() { 

  //raceCondition();
  NonRaceCondition();
  return 0;
}