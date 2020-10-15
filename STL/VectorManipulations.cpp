/*
Template Specification of Vector

Each container has defined for it an allocator. Allocators manage memory allocation
for a container. The default allocator is an object of class allocator, 

template<class T, class Allocator = allocator <T> > class vector 

*/
#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(void) {

    vector<int> vec;

    //Inserts the element at the end of the vector each time
    vec.push_back(1);   
    vec.push_back(2); 

    //Creating the reference to the last element Inserted
    cout<<"Reference to the last Inserted Element "<<vec.back()<<"\n";

    //Creating the reference to the first Element
    cout<<"Reference to the first Inserted Element "<<vec.front()<<"\n";

    //Clearing the whole Vector    
    cout<<"Clearing the Vector\n";
    vec.clear(); 

    //Computing the Size of the vector
    cout<<"Size of the vector is "<< vec.size() << "\n";

    if(vec.empty()) {
        cout<<"Yes Vector is Empty\n";
    }
    

    cout<<"Inserting the Element \n";
    vec.push_back(5);

    if(!vec.empty()) {
        cout<<"Vector is Not Empty,"<< " and Size of the Vector is "<<vec.size();
    }

    //Removing the last inserted Element
    cout<< "Removing the last Inserted element \n";
    vec.pop_back();
    
    if(vec.empty()) {
        cout<<"Yes Vector is Empty\n";
    }

    for(auto i = 0 ; i < 10 ; i++ ) {
        vec.push_back(i);
    }

    for(auto i : vec) {
        cout<< i <<" ";
    }
    cout<<endl;

    // Char Vector
    vector<char> vec2(10);

    for(unsigned int i = 0 ; i < 10 ; i++) {
        vec2[i] = i + 'a';
    }

    //Accessing Vector through an Iterator

    vector<char>::iterator p; //creation of iterator, defined by the container class
    unsigned int j;

    cout<<"Iteration through a vector: ";
    //Iteration through the vector
    p = vec2.begin();
    j = 0 ; 
    while(p != vec2.end() ) {
        cout<< *p << " ";
        p++;
    }
    cout<< endl;
    

    cout<<"Changing the contents of the vector with Iterator: ";
    p = vec2.begin();
    j = 0 ; 
    while(p != vec2.end() ) {
        *p = toupper(*p);
         p++;
    }


    //Iteration through the vector
    p = vec2.begin();
    j = 0 ; 
    while(p != vec2.end() ) {
        cout<< *p << " ";
        p++;
    }
    cout<< endl;

    cout<<"Size of Vector2: "<<vec2.size()<<endl;  

    //
    p = vec2.begin();
    p += 2;

    //vector.insert(position, No of Elements, The Element to be inserted)
    cout<<"Inserting at the position p, with 2 Characters of Z \n";
    vec2.insert(p,2,'Z');

    for(char x : vec2) {
        cout<< x << " ";
    }
    cout<<endl;

    //vector.erase(position, No of elements)
    p = vec2.begin() +2 ;
    vec2.erase(p,p+2);
    cout<<"Erasing the inserted Elements \n";
    for(char x : vec2) {
        cout<< x << " ";
    }
    cout<<endl;

    //Creating Vec3
    cout<<"Copying the contents of Vector2 into Vector3"<<endl;
    vector<char> vec3;
    vector<char>::iterator i3;
    p = vec3.begin();
    vec3.insert(p, vec2.begin(), vec2.end());

    for(char ch: vec3) {
        cout<< ch <<" ";
    }
    cout<<endl;
    return 0;

}