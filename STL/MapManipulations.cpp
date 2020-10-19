/*
map class support association, in which unique keys are mapped with values.
Power of map is that, you can look up a value given its key.
Map can hold only unique keys
To create a map that allows non unique keys, use multimap
map container has the following specification.
*/

#include<iostream>
#include<cstring>
#include<map>
using std::cout;
using std::cin;
using std::map;
using std::string;
using std::pair;
using std::endl;

class name {
    char str[80];
    public :
        name() { strcpy(str, ""); }
        name(char *s) { strcpy(str, s);}
        char *get() { return str;}  
};

//Must define less than relative to name objects.
bool operator<(name a, name b) {
        return strcmp( a.get(), b.get() ) < 0;
}

class phoneNum {
    char str[80];
    public:
        phoneNum() { strcmp(str, ""); }
        phoneNum(char *s) { strcpy(str, s); }
        char *get() { return str; }
};


void sampleMapOperations( void ){

    map<string, int> newMaps;
    newMaps.insert(pair<string,int>("raja",97));
    newMaps.insert(pair<string,int>("rama",98));
    newMaps.insert(pair<string,int>("suchi",99));
    newMaps.insert(pair<string,int>("cnu",100));
    newMaps.insert(make_pair((string)("abc"),101));

    string str;
    cout<<"enter the key: "<<endl;
    cin>>str;

    map<string,int>::iterator p;

    p = newMaps.find(str);
    if(p != newMaps.end())
        cout<<"Its value is: "<<p->second;
    else
        cout<<"Key not in map"<<endl;    
}

void storingClassObjectsInMap( void ) {
    map<name, phoneNum> directory;

    //adding names and numbers into the map
    directory.insert(pair<name, phoneNum> (name("a"), phoneNum("123-456")));
    directory.insert(pair<name, phoneNum> (name("b"), phoneNum("456-789")));
    directory.insert(pair<name, phoneNum> (name("c"), phoneNum("789-123")));
    directory.insert(pair<name, phoneNum> (name("d"), phoneNum("123-789")));
    directory.insert(pair<name, phoneNum> (name("e"), phoneNum("798-456")));

    //finding on name
    char str[80];
    cout<< "Enter a name: ";
    cin>>str;

    map<name, phoneNum>::iterator p;
    p = directory.find(name(str));

    if(p != directory.end())
        cout<< "Phone number: "<< p->second.get();
    else
        cout<<"Name not in directory.\n";


    p = directory.begin();

    /*
    while( p != directory.end()) {
        //cout <<"Name: "<< p->first.get();
        cout<<" Number: "<<p->second.get()<<endl; 
        p++;
    }
    */
    
};

int main(void) {
    
    storingClassObjectsInMap();

    return 1;
}