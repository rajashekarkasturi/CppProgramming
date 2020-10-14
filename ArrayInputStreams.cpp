#include <iostream>
#include <strstream>
#include <array>

using namespace std;

int main(void) {
    char str[100];
    gets(str);

    istrstream ins(str);

    int integerArray[100];

    int i = 0;
    while (ins) {
        ins >> integerArray[i];
        i++;
    }

    cout<< sizeof(integerArray) / sizeof(integerArray[0]);
    return 0;
}