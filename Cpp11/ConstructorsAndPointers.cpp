#include<iostream>
#include<memory>
#include<string>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::unique_ptr;

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
    //std::shared_ptr<Mobile> new_friend; //Has some ownership of the object
    std::weak_ptr<Mobile> new_friend;
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
            cout<< "Mobile Destructor Called " << Mob_name << endl;
        }

        void instanceRAM(int ram = 4) {
            cout<< "The RAM of "<< Mob_name << "is "<< ram << endl;
        }

        void createFriend(std::shared_ptr<Mobile> f) {
            new_friend = f;
        }

        void showFriend() {
            if(!new_friend.expired())   cout << "My Friend is: " << new_friend.lock()->Mob_name << endl;
            //weak_ptr is raw pointer 
            //It make sure that while accessing, the object is not deleted
        
            //We can also print, How many are triggering to that pointer
            cout << "Owned by "<< new_friend.use_count() << " pointer(s). "<<endl;
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

void CustomDeletionOfPointers() {
    std::shared_ptr<Mobile> samsunga21s = std::make_shared<Mobile>("Samsung A21s"); //Uses default deleter
    samsunga21s = nullptr;
    samsunga21s.reset();

    //But when we want to custom delete some objects we need only shared_pointer constructor
    std::shared_ptr<Mobile> samsung30s = std::shared_ptr<Mobile>(new Mobile("Samsung A30s"),
        [](Mobile* ptr) {cout << "Custom Deleting. "; delete ptr;}
        );
    
    //Custom Deletion is very much app;icable when there are array of objects
    std::shared_ptr<Mobile> s20(new Mobile[3]); //here s20 points to only the first object of the array
    //so when p3 is deleted, pointer only deletes the first object. Mobile[1], Mobile[2] can be memory leaked

    std::shared_ptr<Mobile> s10(new Mobile[3], [](Mobile* p) {delete[] p;}); //In this way all three can be deleted once
    // p goes out of scope.

}

void CyclicReferenceOfPointers() {
    shared_ptr<Mobile> Mi(new Mobile("9a"));
    shared_ptr<Mobile> Mi2(new Mobile("7"));
    Mi->createFriend(Mi2);
    Mi2->createFriend(Mi);

    //Output
    //Mobile is instanced: 9a
    //Mobile is instanced: 7

    //Even though using of shared_pointer objects are not deleted,
    //Because we created a cyclic reference. Inorder to rectify we use weak pointers


    
    Mi->showFriend();

    //Output
    //Mobile is instanced: 9a
    //Mobile is instanced: 7
    //My Friend is: 7
    //Owned by 1 pointer(s).
    //Mobile Destructor Called 7
    //Mobile Destructor Called 9a
}

void UniquePointer() {
    //Unique Pointers: exclusive ownership, Light weight smart pointer
    //Unlike shared Pointers, Multiple pointers share the ownership of same object 

    Mobile* nokia = new Mobile("1100");

    nokia->instanceRAM();

    //an old fashion of programming pointers: Explicit Call to delete
    delete nokia;
    //If the program terminates before reaching the delete, It may memory leak
    //So here we use Unique_pointer

    unique_ptr<Mobile> nokia2(new Mobile("Nokia 3.2")); //Automatically destroyed after the scope

    nokia2->instanceRAM(6); 

    //Output
    //Mobile is instanced: 1100
    //The RAM of 1100is 4
    //Mobile Destructor Called 1100
    //Mobile is instanced: Nokia 3.2
    //The RAM of Nokia 3.2is 6
    //Mobile Destructor Called Nokia 3.2

    //Release function here return the raw pointer of the Unique Pointer
    
    //Mobile* nokia3 = nokia2.release();
    //if(!nokia2) {
        //Release Ownership of the object, Unlike shared_ptr
        //cout << "Nokia2 is Empty";
    //}
    
    //If we want to trigger another instance to the pointer
    nokia2.reset(new Mobile("Nokia 6.3"));
    if(!nokia2) {
        cout<< " Nokia 2 is empty"<<endl;
    } else {
        cout << "Nokia 2 is not empty"<<endl;
    }


    //Output
    //Mobile is instanced: Nokia 6.3
    //Mobile Destructor Called Nokia 3.2
    //Nokia 2 is not empty
    //Mobile Destructor Called Nokia 6.3

}

int main( void ) {
    
    //create();
    //create2();
    //CustomDeletionOfPointers(); 
    //CyclicReferenceOfPointers();
    UniquePointer();
    return 1;
}