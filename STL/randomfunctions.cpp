#include<iostream>
#include<cstdlib>
using std::cout;
using std::cin;

int main( void ) {
    
    for(int  i = 0 ; i < 10 ; i++) {
        srand(i);
        cout << rand() % 10 + 1 << " ";
    }
    return 0;
}
