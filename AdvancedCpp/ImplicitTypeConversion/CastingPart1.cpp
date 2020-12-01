#include<iostream>
using std::cout;

/*
 * Type Conversion:
 *  1. Implicit Type Conversion
 *  2. Explicit Type Conversion - Casting
 * 
 */

//-----------1. static_cast-----------------//
class A {
public:
    A() {

    }
    A(std::string name) {

    }
};

class B: public A {
public:
    B() {

    }
};

void staticCastFunction() {

    int i = 9;
    float f = static_cast<float>(i);    //convert object from one type to another.
    A a1 = static_cast<A>(std::string("a1 object"));    //Type conversion needs to be defined.
    A* a2 = static_cast<A*>(new B());   //Convert pointer/reference from one type
                                        // to a related type(down/up cast)
                                        //Derived to base / Base to derived
}

//-----------------Dynamic cast------------------//
void dynamicCastFunction() {
    A*  a2 = new B();
    B b2 = dynamic_cast<B*>(a2);

    //Dynamic_cast only works on pointer/references but not cannot
    // work on object.
    /* a. It convert pointer/reference from one type to a related type (down cast)
     * b. run-time type check. If succeed, b2 == a2; if fail, b2==0;
     * c. It requires the 2 types to be polymorphic (have virtual function).
     */
}

void constCastFunction() {
    const char* str = "Hello";          
    char* changed = const_cast<char*>(str);
    /* Only works on pointer/references
     * Only works on same type
     * cast away constness of the object.
     * Being pointer to
     */
    // char* changed = const_cast<char>(str) will not work.
    // char changed = const_cast<char*>(str) will not work.
}

long p = 100101010;
void reinterpretCastFunctions() {
    A* p = reinterpret_cast<A*>(p);  
    /* Can only work on pointer/references but not objects
     * re-interpret the bits of the object pointed to the ultimate cast that
     * can cast one pointer to any other type of pointer.
     */
}

void CStyleCast() {
    short a = 100;
    int i = (int)a; //c-like cast notation
    int j = int(a); // functional notation
    //   A mixture of static_cast, const_cast and reinterpret_cast
}


int main() {
    //staticCastFunction();
    reinterpretCastFunctions();
    return 1;    
}


/*
 * Generally C++ style of casts are preferred over the C-style, because:
 * 1. Easier to indentify in the code.
 * 2. Less usage error. C++ style provides:
 *      a. Narrowly specified purpose of each cast, and
 *      b. Run-time type check capability.
 */
