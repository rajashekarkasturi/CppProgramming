#include<iostream>
#include<stdexcept>
using std::cout;
using std::cin;
using std::endl;
using namespace std;

/*
//-------9. override------------
//To avoid accidental creation of new function instead of override
int main(void) {

    //C++ 03
    class Dog {
        virtual void A(int);
        virtual void B() const;
    };

    class ExtendedDog : public Dog {
        virtual void A(float) {
            cout<<"In Virtual Extended A"<<endl;
        }; //created a new function instead of overriding 

        virtual void B() {
            cout<<"In Virtual Extended B "<<endl;
        };  //created a new function instead of overriding
    };

    //C++ 11
    class Dog1 {
        virtual void A(int);
        virtual void B() const;
        void C();
    };

    class ExtendedDog1 : public Dog1 {
        virtual void A(float) override{
            cout<<"In Virtual Extended A"<<endl;
        }; // Error: No Function to override 

        virtual void B() override{
            cout<<"In Virtual Extended B "<<endl;
        };  //  Error: No Function to override

        void C() override;
        // Error: no function to override (Not virtual)
    };    

    return 1;
}
*/

/*
//-------------10. Final-------------
//final (for virtual function and for class)
class dog final {   // no class can be derived from dog

};
class dog {
    virtual void bark() final; //No class can override bark()
};
*/

/*
//------------11. Compiler Generated Default Constructor----

//C++ 03
class Dog {
    dog(int age) {}
};
dog d1; //Error: Compiler will not generate the default constructor

//C++ 11
class Dog {
    dog(int age);
    dog() = default; // Force compiler to generate the default constructor
};

*/

/*
//-------------12. delete----------
int main() {

//C++ 03
class Vehicle{
    Vehicle(int age) {  age += 2;};
};
    Vehicle v1(2);
    Vehicle v2(3.0); // 3.0 is converted to double to int
    a = b;           // compiler generated assignment operator


    //C++ 11
    class Vehicle2 {
        Vehicle2(int age) {}
        Vehicle2(double) = delete;
        Vehicle2& operator=(const Vehicle2&) = delete;
    };

    return 1;
}    
*/

/*
//------------13.constexpr-------------

int computeCube(int);
int main(void) {
    
    int arr[6]; //OK
    int A() { return 3; }
    int arr[A()+3]; //Compile Error

    //C++ 11
    constexpr int B() { return 3;}  //Forces the computation to happen at a compile time
    
    int arr2[B() + 3];  //Create an array of size 6

    //Example Program with constexpr
    constexpr int computeCube(int x) {  return x*x*x;   }

    int y = computeCube(1789);  //Computed at compile time
    return 1;
}
*/


/*
//------------14. New String Literals----------
//Better support for Unicode characters
int main(void) {
    //C++ 03:
    char* str = "rajashekar";

    //C++ 11:
    char*     s1 = u8"sample";  // to define an UTF-8 string.
    char16_t* s2 = u"sample";   // to define an UTF-16 string.
    char32_t* s3 = U"sample";   // to define an UTF-32 string.
    char*     s4 = R"string \\";   // TO define a raw string.

    cout<<"Hello World"<<endl;
    return 1;
}
*/

int main(void) {
    
}