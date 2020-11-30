/*
    Calling Virtual Function in Constructor and Destructor
*/
#include<iostream>
using std::cout;
using std::endl;

class A{
    public:
        A() {
            cout << "A Constructor. " << endl;
            print();    //prints print() of A() rather calling B class print()
        }
        virtual void print() {  //virtual makes the object to call explicit function of that particular class
            cout << " I am from A Class. " << endl;
        }
        void callPrintA() {
            print();
        }
};

class B : public A{
    public:
        B() {
            cout << "B Constructor. " << endl;
        }
        virtual void print() {
            cout << "I am from B Class. " << endl;
        }
};

int main(void) {
    B b1;
    b1.callPrintA();    //invokes B class print (Dynamic Binding)
    //Output
    //A Constructor.
    //B Constructor.
    //I am from B Class.    

    return 0;
}

/*
Calling function in a constructor should be avoided and Destructor(To avoid unnecessary call to function
after the object being destroyed).
*/