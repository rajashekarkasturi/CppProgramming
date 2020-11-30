#include<iostream>
#include<vector>
using std::cout;
using std::endl;

class A {
    public :
        A(std::string name) { name_ = new std::string(name);  }
        ~A() { delete name_; }
        A(const A& rhs) {  
            name_ = new std::string(*(rhs.printA())); 
        }
        A& operator=(const A& rhs);//Deep copy
        void printName() {  cout << *name_; }
        std::string* printA() const { return name_; }

    private:
        std::string* name_;
};

//Solution 1: Define copy constructor and copy assignment operator for deep copying.
//Solution 2: Delete copy constructor and copy assignment operator
            //Make them private such that its children or friends cannot use them,


int main() {

    std::vector<A> a1;
    a1.push_back(A("Hello a1"));    //Rvalue which will be destroyed at the end of the statement.
    //For older standard the following steps happen for the above line of code.
    //1. "Hello a1" is constructed
    //2. A copy of "Hello a1" is saved in the vector a1. (Shallow copy)
    //3. "Hello a1" is destroyed( so causing unaccessed to printA())

    cout<< "in" <<endl;
    a1.back().printA();
    cout<< "out" <<endl;

    return 0;
}


/*
If we want to use the copy of an object without using the copy constructor, define clone()
so that copying can be done explicitly

A* clone*() {
    return (new A(*(name_)));
}
*/