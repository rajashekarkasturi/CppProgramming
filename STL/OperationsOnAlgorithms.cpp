#include<iostream>
#include<vector>
#include<list>
#include<cstdlib>
#include<algorithm>
using std::list;
using std::vector;
using std::cout;
using std::cin;
using std::boolalpha;
using std::endl;
using std::type_info;

void countAlgorithm( void ) {

    vector<bool> v;
    unsigned int i;

    for(i = 0 ; i < 10 ; i++) {
        if (rand()%2)
            v.push_back(true);
        else 
            v.push_back(false);
    }

    cout<< "Sequence: \n";
    for(i = 0 ; i < v.size() ; i++) 
        cout<< boolalpha << v[i] << " ";
    cout<<endl;

    i = count(v.begin(), v.end(), true);
    cout<< i << " Elements are true \n";

}

bool PrimeNumbers(int i) {
    if(i == 1)
        return false;
    else if( i == 2 || i == 3)
        return true;
    else {
        int flag = 0;
        for(int j = 2 ; j < i ; j++) {
            if(i % j == 0)
                flag = 1;
        }
        if(flag == 0 )
            return true;
        else 
            return false;
    }
}

void countIfAlgorithm( void ) {

    vector<int> vec;
    for(int i = 1 ; i < 20 ;i++)
        vec.push_back(i);
    cout<<endl;

    int i = count_if(vec.begin(), vec.end(), PrimeNumbers);
    cout<< i <<": Numbers are Prime Numbers"<<endl;    

}

int multiply(int i) {
    return i*i;
}

void removeReplaceReverseTransformation( void ) {

    char str[] = "Hello This is Rajashekar.";
    vector<char> v1,v2(30);
    unsigned int i;
    for(i = 0 ; str[i] ; i++)    v1.push_back(str[i]);    

    cout<< "V1 Vector contents:\n";
    for(i = 0 ; i < v1.size(); i++) cout<< v1[i];
    cout<<endl;
    

    //remove all spaces
    remove_copy(v1.begin(), v1.end(), v2.begin(), ' ');

    //v2 Vector
    cout<<"\nV2 vector contents:\n";
    for(i = 0 ; i < v2.size(); i++) cout<<v2[i];
    cout<<endl;

    cout<< "\nV1 Vector contents:\n";
    for(i = 0 ; i < v1.size(); i++) cout<< v1[i];
    cout<<endl;

    //replace copy
    replace_copy(v1.begin(), v1.end(), v2.begin(),' ', ';');

    //v2 Vector
    cout<<"\nV2 vector contents:\n";
    for(i = 0 ; i < v2.size(); i++) cout<<v2[i];
    cout<<endl;

    cout<< "\nV1 Vector contents:\n";
    for(i = 0 ; i < v1.size(); i++) cout<< v1[i];
    cout<<endl;

    reverse(v1.begin(), v1.end());

    cout<< "\nV1 Vector contents:\n";
    for(i = 0 ; i < v1.size(); i++) cout<< v1[i];
    cout<<endl;

    list<int> l;
    for(int i = 0 ; i < 10 ; i++)    l.push_back(i);

    cout<<"\nOriginal contents of list\n";
    list<int>::iterator p;
    p = l.begin();
    while(p != l.end()) {
        cout<<*p<<" ";
        p++;
    }
    cout<<endl;

    p = transform(l.begin(), l.end(), l.begin(), multiply);

    cout<<"After Modification\n";
    p = l.begin();
    while(p != l.end()) {
        cout<<*p<<" ";
        p++;
    }
    cout<<endl;  
    
}

int main( void ) {

    removeReplaceReverseTransformation();
    return 1;
}