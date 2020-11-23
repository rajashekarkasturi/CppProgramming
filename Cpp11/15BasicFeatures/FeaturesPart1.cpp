#include<iostream>
#include<vector>
#include<initializer_list>
#include<cassert>
using std::cout;
using std::endl;

#define assertm(exp, msg)   assert ((void)msg, exp))

/* 1. Initializer List: of own Type or any STL Container Type
class RVector {
    std::vector<int> new_vec;
    public :
    RVector(const std::initializer_list<int>& v) {
        for(std::initializer_list<int>::iterator itr = v.begin(); itr != v.end(); itr++) {
            new_vec.push_back(*itr);
        }
    }
};
 
int main(void) {
    vector<int> v1 = {0, 1, 2, 3, 4};
    vector<int> v2{5, 1, 4, 3, 2};
    RVector r1 = {1, 2, 3, 4, 5};
    return 1;
}
*/

/*
//---------2. Uniform Initialization----------------//
// C++ 03
class Employee {
    public:
    int id;
    std::string name;
};

Employee e1 = {5, "abc"}; //Aggregate Initialization

// C++ 11 extended the scope of curly brace init

class Employee1 {
    public:
    Employee1(int roll, std::string name) {
        
    }
};

Employee1 e2 {6, "bcd"};

//Uniform Initialization Search Order

//  1. Initialization_list constructor
//  2. Regular constructor that takes the appropriate parameters
//  3. Aggregate Initializer

*/

/*
//--------------3. auto type --------------
int main(void ) {
std::vector<int> new_vec1 = {5, 4, 1, 3, 2};

    //C++ 03
    cout<<endl<<"Traditional way"<<endl;
    for(std::vector<int>::iterator it = new_vec1.begin(); it != new_vec1.end() ; it++) {
        cout<<*it<<" ";
    }

    //C++ 11: use of auto type
    cout<<endl<<"Using auto keyword"<<endl;    
    for(auto itr = new_vec1.begin(); itr != new_vec1.end(); itr++) {
        cout<<*itr<<" ";   
    }
    cout<<endl;

    auto a = 9; // a is an integer
    auto b = 6.6; // b is a double
    auto c = a;  // a is an integer 
    
    return 1;
}
*/

/*
//-----------4. foreach -----------
int main(void) {
    std::vector<int> v2{1,2,3,4,5};
    
    //C++ 03:    
    for(std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    
    //C++ 11:
    for(auto i : v2) {

        cout<<i<<" ";
    }
    cout<<endl;
    //Overriding values
    for(auto& j: v2) {
        j++;
        cout<<j<<" ";
    }

    return 1;
}
*/

/*
//-------5. nullptr-------------
void foo(int i) {   cout <<"foo_int" <<endl; }
void foo(char* ptr) {   cout <<"foo_char*" <<endl;   }
int main(void) {
    foo(NULL);  //Ambiguity

    //C++ 11
    foo(nullptr); // call foo(char*)
}
*/

/*
//---------6. enum class----------

int main(void) {
    //C++ 03
    enum languages{c_lang, cpp_lang}; //basically integer values
    enum scripting{bash_script, shell_script};
    languages a = c_lang;
    scripting s = bash_script;

    if(a == s)
        cout<<"both the first terms are same";
    else
        cout<<"They are not same";


    //C++ 11
    enum class languages1{c_lang, cpp_lang}; //basically integer values
    enum class scripting1{bash_script, shell_script};
    languages1 a = languages1::c_lang;
    scripting1 s = scripting1::bash_script;

    if(a == s)
        cout<<"both the first terms are same";
    else
        cout<<"They are not same";

    //Compilation fails because we need to override ==(languages, scripting)    
    return 1;
}

*/

/*
//---------7. static_assert----------

int main(void) {
    //run-time assert
    assert(2+2 == 4);
    cout<<endl<<"Goes down"<<endl;
    
    //C++ 11: compile time assert checking
    static_assert(sizeof(int) == 4);
    //continues if the integer size is 4 or else exits
    cout<<"Integer size is 4"<<endl;
    return 1;
}
*/

/*
//------------8. Delegating Constructor-------------
//Sample Code: Cannot be compiled

//This can be done in Java
class Car {
    public:
    Car() {

    }
    Car(int a) { 
        Car();
        otherFunctions();
    }
};

//C++ 03
class Car {
    init() { ... };
    public:
    Car() { init(); }
    Car(int a) {init(), otherFunctions();}
};
//Cons:
//1 . Redundant Code
//2. init() could be invoked by other functions.


//C++ 11
class Car {
    int age = 9;
    public:
    Car() {...}
    Car(int a) : Car() {otherThings();}
};
// Limitation: Car() has to be called first
// Also C++ allows in-Class data memebers initializtion, Here age will be initialized for every constructor

*/
