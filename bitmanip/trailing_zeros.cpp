#include<iostream>

int trailing_zeros(int n) {
    int cnt = 0;
    while(n>0){
        if(n&1) {
            break;
        }
        ++cnt;
        n>>=1;
    }
    return cnt;
}

int main() {
    int n = 12;
    std::cout << trailing_zeros(n) << std::endl;
    return 0;
}