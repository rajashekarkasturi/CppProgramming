#include<iostream>
using std::cout;
using std::endl;

// User Defined Implicit Type Conversion
/*
 * Categories of Type Conversion:
 *                                  Implicit    Explicit
 * Standard Type Conversion            A            B
 * User Defined Type Conversion        C            D
 *                                              (Casting)
 * 
 */


void CategoryA() {
    //Category A: Implicit Standard Type Conversion
    
    char c = 'A';
    int i = c;  // Integral Promotion

    char* pc = 0;    // int -> Null pointer

    //void f(int i);
    //f(c);

    //A* a1 = new B();  //Pointer type conversion.

}


class A {
    public:
        A(std::string name) { new_name = name; }    //No Explicit
        /* I fwe only want to define a constructor, and we dont want
         * any explicit type conversion, always put "explicit" before the
         * constructor to avoid inadvarent type conversion. 
         */
        
        //std::string getName() { return new_name;}
        operator std::string () const { return new_name; }

    private:
        std::string new_name;    
};

void CategoryC() {
/*
 * Category C: Implicit User Defined Type Conversion
 * 
 * Defined inside class (user defined type)
 * 
 * There are 2 methods to define implicit user defined type conversion:
 * Method 1: Use constructor that can accept a single parameter.
 *      - convert other types of object into your class
 * Method 2: Use the type conversion function
 *      - convert an object of your class into other types
 */
    std::string name = "Bob";
    A a1 = name;
    //cout << "Name is " << a1.getName() << endl;
    //Output
    //Name is Bob

    //Instead we can use the followig
    printf("Name is %s", a1);


    //If we want to avoid implicit type conversion use explicit keyword
    //explicit A(std::string name) { new_name = name; }

    /* 1. Avoid defining seemingly unexpected conversion. //A a2 =a1;
     * 2. Avoid defining two-way implicit conversion.   //cyclic conversion.
     */

}



int main() {
    //CategoryC();
    return 0;
}