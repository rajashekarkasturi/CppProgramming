/*

template <class Ttype> ret-type func-name(parameter list)
{
    // body of function
}

*/

#include<iostream>
using namespace std;

template <class X> void swapargs( X &a, X &b) {
    
    X temp;

    temp = a;
    a = b;
    b = temp;
}

template <class X, class Y> void function(X a, Y b) {
    cout<< a << ' '<< b << '\n';
}

void singleGenericTemplate(void) {
        int i = 0 , j = 1;
    double a = 5.0, b = 10.0;
    char x = 'a', y = 'b';

    cout<<" Orginal"<<endl;
    cout<<" i = "<<i<<endl;
    cout<<" j = "<<j<<endl;
    cout<<" a = "<<a<<endl;
    cout<<" b = "<<b<<endl;
    cout<<" x = "<<x<<endl;
    cout<<" y = "<<y<<endl;

    swapargs(i,j);
    swapargs(a,b);
    swapargs(x,y);

    cout<<" i = "<<i<<endl;
    cout<<" j = "<<j<<endl;
    cout<<" a = "<<a<<endl;
    cout<<" b = "<<b<<endl;
    cout<<" x = "<<x<<endl;
    cout<<" y = "<<y<<endl;

}

void TwoGenerics(void) {
    function(10, "Hello Everyone!");
    function(88.1465, 19L);
}

template <class Ctype, int size> class A {
    Ctype a[size];
    public :
        A() {
            register int i;
            for(i = 0 ; i < size ; i++) a[i] = i;
        }
        Ctype &operator[](int i );
}; 

template <class Ctype, int size>Ctype &A<Ctype, size> :: operator[](int i) {

    if(i < 0 || i > size - 1 ) {
        cout<<"\nIndex value of ";
        cout << i << " is out-of-bounds. \n";
        exit(1);
    }
    return a[i];
}

void ClassTemplates(void) {

    A<int, 10> intob;
    A<char, 10> charob;

    int i;

    cout << " Integer array: ";
    for(i = 0 ; i < 10 ; i++) intob[i] = i;
    for(i = 0 ; i < 10 ; i++) cout<< intob[i] << " ";
    cout<< '\n';

    cout<< "Char array: ";
    for(i = 0 ; i < 10; i++) charob[i] = (i+97);
    for(i = 0 ; i < 10 ; i++) cout<< charob[i] << " ";
    cout<< '\n';

}


int main(void) {
    
    return 0;
}