#include<iostream>
using std::cout;
using std::endl;


class Dog1 {

};
//--------Dog1 is Equivalent to Dog---------
class Dog {
    public:
        
        Dog(const Dog& arg) {    
            //SampleCode
        
        }   //Member by member initialization

        Dog& operator=(const Dog& args) {
            //Sample Code
            return *this;
        }   //Member by member copying

        Dog() {
            //Sample Code
        };  //1. Call base class's default constructor;
            //2. Call data memeber's default constructor.

        ~Dog() {
            //Sample Code

        }   //1. Call base class's default destructor
            //2. Call data member's destructor.

};

class BankLogin {
    
    public:
        std::string _userId;

        BankLogin(std::string userId = "DefaultUser") {
            _userId = userId;
            cout << _userId << " Logged In." << endl;
        }

        ~BankLogin() {
            cout << _userId << " Logged Out." << endl;
        }        
};

void LoggingUsers() {
    BankLogin u1("User1");
    BankLogin u2;
    u2 = u1;

    //Output:
    //User1 Logged In.
    //DefaultUser Logged In.
    //User1 Logged Out.
    //User1 Logged Out.

}

int main() {
    LoggingUsers();
}