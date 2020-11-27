#include<iostream>
#include<vector>
using std::cout;
using std::endl;

//const
//  -A compile time constraint that an object can not be modified.

/*
void definitionConst() {
    //i = 11; //error: assignment of read-only variable 'i'

    const int *ptr = &i; //data is const, pointer is not
    //*ptr = 5; //error
    ptr++;

    int* const ptr2;    //pointer is const, data is not

    const int* const ptr3;  //data and pointer both are constant.

    int const *ptr4 = &i;
    const int *ptr = &i;

    //Rule
    //1. If const is on the left of the *, data is const
    //2. If const is on the right of the *, pointer is const    
}
*/

void changingConst() {
    const int i = 10;
    cout << i << endl;

    const_cast<int&>(i) = 11;   //Trying to the change the constness
    cout << i << endl;

    int j;
    static_cast<const int&>(j); //Trying to make it const using static_cast

    /*
        Why use const
        1. Guards against unintentional write to the variable.
        2. Self documenting
        3. Enables compiler to do more optimization, making code tighter.
        4. const means the variable can be put in ROM.
    */    
}

void constWithFunctions() {

    Mobile mob1;
    cout<< "Old RAM " << mob1.getRAM() <<endl;

    int newRam = 4;
    mob1.setRAMexplicit(newRam);
    cout << newRam << endl;
    cout<< "New RAM " << mob1.getRAM() <<endl;


    mob1.printName();
    const Mobile mob2;
    mob2.printName();

}

class Mobile {
    std::string name;
    const int RAM = 4;

    public:
        //const paramters
        Mobile() {  name = "Android";}
        void setRAMexplicit(const int& newRAM) {
            const_cast<int&>(RAM) = RAM + newRAM;
        }

        int getRAM() {
            return RAM;
        }


        //const return value
        const std::string& getName() {
            return name;
        }


        //const functions
        //we cannot modify any variables of class
        //it can only accomodate const functions

        //Const Objects call const functions
        void printName() const { cout << name << "const name << "<< endl;}

        //non const objects call non const functions
        void printName() { cout << getName() << "non name << "<< endl;}        

};

class DataAccess {
    std::vector<int> v;
    mutable int accessedTimes = 0;  //Variable can be changed in const function
    int casting_variable = 0;   //another solution of removing constness
    public :
        int getItem(int index) const {
            accessedTimes++;    //The compiler maintaines the concept of bitwise constness (Conflict between logic constness and Bitwise constness)
            //Can be solved by making the member as mutable

            const_cast<DataAccess*>(this)->casting_variable++;

            return v[index];
        }

};

void logicAndBitwiseConstness() {
    DataAccess d1;
}

int  main() {
    
    //definitionConst();
    //changingConst();
    //constWithFunctions();
    logicAndBitwiseConstness();

    return 1;    
}
