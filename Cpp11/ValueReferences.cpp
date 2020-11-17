#include<iostream>
using std::cout;
using std::cin;
using std::endl;


//C++ 11:Rvalue Reference
//1. moving semantics
//2. Perfect forwarding

/*
void foo(int& i) {  cout << "lvalue reference: "<< i << endl;   }
void foo(int&& i) { cout << "rvalue reference: "<< i << endl;   }
int main( void ) {
    int a = 5; //a is a lvalue
    int& b  = a; // b is a lvalue reference
    int&& c = 3; // c is a rvalue reference

    foo(a);
    foo(6);

    return 1;
}
*/
    /*
    Move Constructor/Move Assignement Operator:
    ---Purpose: conveniently avoid costly and unnecessary deep copying
    ---1. They are particularly powerful where passing by reference
            and passing by value are both used
    ---2. They give finer control of which part of our objec to be moved.
    */


   //Forwarding References
   /*
   Reference Collapsing Rules ( C++ 11 ):
   1. T& &  => T&
   2. T& &&  => T&
   3. T&& &  => T&
   4. T&& &&  => T&& 
   */
    
    /*
    template< class T>
    struct remove_reference;    //It removes refernce on type T

    //T is int&
    remove_reference<int&>::type i;  // int i;

    //T is int
    remove_reference<int>::type i;  // int i;
    */

template< typename T>
void foo(T&& arg) {
    cout<<"converts to lvalue or rvalue based on the type of args"<<endl;
}

int main(void) {
    int x = 5; //lvalue

    //T&& variable is initialized with rvalue => rvalue reference 
    foo(9); // T = int&& => T&& =  int&& &&=> int&&
    
    //T&& variable is initialized with lvalue   => lvalue reference
    foo(x); // T = int& => T&& = int& && = int&

    //std::move() and std::forward()
    //std::move<T>(arg);  //Turn arg into an rvalue type
    //std::forward<T>(arg);   //Turn arg into type of T&&

    return 1;
}
