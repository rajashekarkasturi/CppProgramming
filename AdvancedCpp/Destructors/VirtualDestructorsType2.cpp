#include<iostream>
#include<memory>    //shared_ptr
using std::cout;
using std::endl;

class A {
    public:
    ~A() {  cout << "A Destroyed " << endl; }
    virtual void printA() {}
};

class B : public A {
    public:
        ~B() { cout << "B Destroyed " << endl; }
};

class Alpha {
    public:
        static std::shared_ptr<A> createB() { 
            return std::shared_ptr<B>(new B()); 
        }
        // ....
};

int main() {
    std::shared_ptr<A> ptr = Alpha::createB();

    return 0;
}


/*
Note: All classes in STL have no virtual destructors, 
        so there is close call while inheriting from them
*/