#include<iostream>
using std::cout;
using std::endl;


//Dynamic cast needs types to be polymorphic, so need to have atleast one virtual function.
class A {
public:
    virtual ~A() {  }
};

class B: public A {
    int number;
    public:
        void print() {
            cout << "Inside B: Number is" << endl;
        }
};

void DynamicCastandPoly() {
    A* a1 = new A();
    //Unfortunately
    B* b1 = dynamic_cast<B*>(a1);
    b1->print();
    cout << "b1 " << b1 << endl;
    cout << "a1 " << a1 << endl;
    //Output :: here the print function is treated as static because of no access to member variables.
    //Inside B
    //b1 0
    //a1 0x949f88

    /*Better to use Dynamic cast and polymorphism*/
    
}


class C {
    public:
        int number;
        C():number(5) {}
    void print() const {
        std::cout << "Number is " << number << std::endl;
        const_cast<C*>(this)->number = 6;
    }
};
int main(void) {
    C c1;
    c1.print();
    cout << "After call to print: " << c1.number << endl;

    //Output
    //Number is 5
    //After call to print: 6

    return 0;
}