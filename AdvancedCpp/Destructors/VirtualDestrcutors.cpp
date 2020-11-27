#include<iostream>
using std::cout;
using std::endl;

class A {
    public:
    virtual ~A() {  cout << "A Destroyed " << endl; }
};

class B : public A {
    public:
        ~B() { cout << "B Destroyed " << endl; }
};

class Alpha {
    public:
        static A* createB() { return (new B()); }
        // ....
};

int main() {
    A* ptr = Alpha::createB();

    delete ptr;

    //After executing this we get the output as
    //A Destroyed

    //Inorder work correctly we need to make ~A() virtual

    return 0;
}
