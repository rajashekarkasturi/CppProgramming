class A {
public:
    virtual A* clone() {return (new A(*this)); }    // co-variant return type
};

class B: public A {
    virtual B* clone() {return (new B(*this)); }    
};
//Here Clone functions like a virutal constructor


void foo(A* b1) {     //b1 object is of B 
    //A* a1 = new A(*b1);   // a1 object is of A
    A* a1 = b1->clone();
}

int main(void) {
    B b1;
    foo(&b1);
}