#include<iostream>
class A {

};


int main() {
    //Lvalue Examples:
    int i;  // i is a lvalue
    int* p = &i;    // i's address is indentifiable
    i = 2;  // Memory content is modified.

    A a1;   // lvalue of user defined type (class)
            // Most variables in C++ code are lvalues
    
    //Rvalue Examples:
    int x = 2;  // 2 is an rvalue
    int x = i+2; // (i+2) is an rvalue
    //int* p = &(i+2);    // Error
    //i + 2  = 4 ;
    //2 = i;  //Error (lvalue Required)

    A a1;
    a1 = A();   // dog() is rvalue of user defined type (class)

    int sum(int x, int y) { return x+y; }
    int i = sum(2, 4);  //sum(2,4) is rvalue

    //Reference (or lvalue reference):
    int i;
    int& r = i;
    //int& r = 5;   //Error

    //Exception: Const lvalue reference can be assign a rvalue
    const int& q =5; 



    int square(int& x) {    return x*x; }
    square(i);  //OK
    //square(40); // Error

    //Workaround:
    int square1(const int& x) {  return x*x; }   //Square(40) and Square(i) will work
    
    //Lvalue can be used to create an rvalue
    int i = 1;  //i is lvalue
    int x = i + 2;  //Now we made it as an rvalue

    int x = i;  // lvalue(Implicit transformed to rvalue)


    //rvalue can be used to create an lvalue
    int v[3];
    *(v+2) = 4;


    //Misconception 1: Function or Operator always yields rvalues

    int x = i;
    return 1;
}