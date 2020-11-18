#include<iostream>
#include<memory>
#include<string>
using std::cout;
using std::endl;

/*
 //C++ 03:
 * 1. default constructor (generated only if no constructor is declared by user)
 * 2. copy constructor (generated only if no 5, 6 declared by user)
 * 3. copy assignment operator ( generated only if 5,6 are not declared by user)
 * 4. destructor
 
 //C++ 11:
 * 5. move constructor ( Generated only if 2,3,4,6 not declared by user)
 * 6. move assignment operator (Generated only 2,3,4,5 not declared by user)
 */

/*
class Dog {
    // C++ 03:
    Dog();              //default constructor
    Dog(const Dog&);    //copy constructor
    Dog& operator=(const Dog&); // copy assignment operator
    ~Dog();

    // C++ 11:
    Dog(Dog&&);     // move constructor
    Dog& operator=(Dog&&);  // move assignment operator
};
*/

class Mobile {
    std::string Mob_name;
    int RAM;
    public:
        Mobile(std::string name) {
            Mob_name = name;
            cout<<"Mobile is instanced: "<< name <<endl; 
        }
        
        Mobile() {
            Mob_name = "No Name";
            cout<< "This is a call to default constructor"<< Mob_name << endl;
        }

        ~Mobile() {
            cout<< " Mobile Destructor Called" << Mob_name << endl;
        }

        void instanceRAM(int ram = 4) {
            cout<< "The RAM of "<< Mob_name << "is "<< ram << endl;
        }

};

void create() {
    Mobile* ptr = new Mobile("SAMSUNG");

    ptr->instanceRAM(); //If the pointer is kept not free even after the function ends
                        //It may lead to memory leak

    //In the long run of development we cannot explicitly delete particular pointers created
    //This is why we need smart pointers, those are present in <memory> headers     
    //This is why we use the concept in C++ 11 shared pointers


    std::shared_ptr<Mobile> p(new Mobile("GOOGLE"));
    {   
        cout<< "Use Count " << p.use_count() << endl;
        p->instanceRAM(6);
    }
    //Output
    //Mobile is instanced: SAMSUNG
    //The RAM of SAMSUNGis 4
    //Mobile is instanced: GOOGLE
    //Use Count 1
    //The RAM of GOOGLEis 6
    //Mobile Destructor CalledGOOGLE

}

void create2() {
    // An object should be assigned to a smart pointer as soon as it is created. Raw pointer should not be used.
    Mobile* ptr = new Mobile("Mi"); //Not an efficient way

    //std::shared_ptr<Mobile> p2(ptr);    // p.use_count() == 1
    //std::shared_ptr<Mobile> p3(ptr);    // p2.use_count() == 1
    //here two shared pointer accessing only one object of Dog. This may lead to errors

    //The best way to do it is
    Mobile* iphone = new Mobile("12 Mini");
    std::shared_ptr<Mobile> iphone12 = std::make_shared<Mobile>("12 Pro Max");  //faster and safer

    //Just like we cast raw pointer we can cast shared_pointer
    //static_pointer_cast
    //dynamic_pointer_cast
    //const_pointer_cast
}


int main( void ) {
    
    create();
    create2();
    
    return 1;
}