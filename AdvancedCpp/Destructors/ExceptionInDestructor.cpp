#include<iostream>

using std::cout;
using std::endl;

class A {
    public:
    std::string A_name;
    A(std::string _name) {  A_name = _name; cout << A_name << " is created. " << endl; }
    ~A()    {   cout << A_name << " is destroyed. " << endl ;}
    void printA() { cout << "a is printed. " << endl; throw 12;}
};

int  main() {
    try {
        A a1("a1 object ");
        A a2("a2 object ");
        //throw 12;
        a1.printA();
        a2.printA();
    }
    catch(int e) {
        cout << e << " Exception is caught \n";
    }

    return 1;
}


/*
Note:
1. Objects created in Try are executed in the stack manner, 
    so they are destructed in reverse order of pop before coming out of it
2. C++ doesn't accomodate more than one pending exception
    when there is throw is in destructor in the above program. It will crash. 
*/

/*
---Output when throw is in try block---
a1 object  is created.
a2 object  is created.
a2 object  is destroyed.
a1 object  is destroyed.
12 Exception is caught
*/

/*
Solution 1: Destructor Swallow the exception.

~A() {
    try {
        //Enclose all the exception prone code.
    } catch(Exception e) {
        // Catch exception
    } catch(...) {
        //This type of exception allows anytype but does not produce the stack trace.
    }
}
*/

/*
    Solution 2 - Move the exception-prone code to a different function.
*/