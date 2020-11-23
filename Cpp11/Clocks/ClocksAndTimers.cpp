#include<iostream>
#include<chrono>
using std::cin;
using std::cout;
using std::endl;


/* <chrono>
    -Precision-neutral library for time and date

    Clock:
    system_clock(C++11): wall clock time from the system-wide realtime clock(class) - is not steady

    steady_clock(C++11): monotonic clock that will never be adjusted(class) [goes at a uniform rate]

    high_resolution_clock(C++11): the clock with the shortest tick period available(class)

    std::chrono::duration<>: //time duration    
*/

int main( void ) {

    std::ratio<1,10> r;
    cout << r.num << "/" << r.den << endl;
    
    cout << std::chrono::system_clock::period::num << "/" << std::chrono::system_clock::period::den << endl; 

    std::chrono::microseconds mi(2500); //2700 microseconds
    std::chrono::nanoseconds na = mi;   //from lower resolution to higher => micro to nano => 2500000 nanoseconds
    std::chrono::milliseconds millis = std::chrono::duration_cast<std::chrono::milliseconds>(mi);   // 2 milliseconds(2.5) here 5 is truncated
    //higher to lower resolution(micro - milli) needs casting

    cout << "Micro seconds: " << mi.count() << endl;
    cout << "Nano seconds: " << na.count() << endl;
    cout << "Milli seconds: " << millis.count() << endl;


    //reference of time => point of  time => std::chrono::time_point<>
        //00:00 January 1, 1970 (Corodinated Universal Time - UTC)  --epoch of a clock

    std::chrono::system_clock::time_point _time_point = std::chrono::system_clock::now();    //current time of system_Clock
    cout << _time_point.time_since_epoch().count() << endl;


    std::chrono::steady_clock::time_point _start_now = std::chrono::steady_clock::now();
    cout << "C++ 11" << endl;
    std::chrono::steady_clock::time_point _end_now = std::chrono::steady_clock::now();
    std::chrono::steady_clock::duration d = _end_now - _start_now;

    if( d == std::chrono::steady_clock::duration::zero())
        cout << "No time is elapsed";
    cout << std::chrono::duration_cast<std::chrono::microseconds>(d).count() << endl;

    return 1;
}