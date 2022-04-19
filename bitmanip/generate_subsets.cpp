#include<iostream>

int main() {
    int n = 3;
    int m = 1 << n;
    for(int i =  1; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if((i>>j)&1) {
                std::cout << j+1 << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}