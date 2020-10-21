
/*
Null terminated string cannot be manipulated by any of the standard C++ operators.
Container Class: String, to include add <string>.
Safe and fully integrated way to manage strings

General String constructors
string(); //creates an empty string object
string(const char *str); //covertes a string from null terminated string pointed by str
string(const string &str); // creates a string from another string

= Assignment
+ Concatenation
+= Concatenation assignment
== Equality
!= Inequality
< Less than
<= Less than or equal
> Greater than
>= Greater than or equal
[ ] Subscripting
<< Output
>> Input

*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


void stringOperations( void ) {
    string str1("srh");
    string str2("rcb");
    string str3("csk");
    string str4;

    //assigning a string
    str4 = str1;
    cout<<str4;

    //concatenate two strings
    str4 = str1 + str2;
    cout<<str4;

    str4 = "dc";
    cout<<str4;

    //clearing the string
    str4.clear();

    //checking if both are equal or not
    if(str1 != str2)
        cout<<"Strings are not equal\n";
    
    //assign is used for assigning the partial strings,
    // rather you can use the general = to assign whole string
    str4.assign(str3, 2, 1);
    cout<<str4;
    //we can also append string using append()
    //we will need this if we are appending a partial string

    //insert, erase, replace
    /*
        string &insert(size_type start, const string &strob);
        string &insert(size_type start, const string &strob, size_type insStart, size_type num);
        string &replace(size_type start, size_type num, const string &strob);
        string &replace(size_type start, size_type orgNum, const string &strob, size_type replaceStart, size_type replaceNum);                
        string &erase(size_type start = 0, size_type num = npos);
    */

    //searching a string

    //string as Container
    string::iterator p;

    int c = count(str1.begin(), str1.end(),'r');
    cout<<endl<<c<<endl;

    //transform(str1.begin(), str1.end(), str1.begin(),toupper);

    p = str1.begin();
    while( p != str1.end()) {
        cout<< *p;
        p++;
    }
    cout<<endl;

    

}

int main( void ) {

    stringOperations();
    
    return 0;
}