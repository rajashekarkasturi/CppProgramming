#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::endl;

template<typename func>
void filter(func f, std::vector<int> arr) {
    for(auto i : arr) {
        if(f(i))
            cout<< i << " ";
    }
}

void usingLambda(void) {
    cout<< [](int x, int y) { return x+y; }(3,5) << endl;   //8
    auto f = [](int x, int y) { return x+y; };
    cout<< f(10,12) << endl;    //22
    
    std::vector<int> v{1,2,3,4,5};

    filter( [](int x) { return (x>3);}, v); //Output 4 5 
    cout<< endl;
    filter( [](int x) {return (x > 2 && x < 5); }, v);  // Output: 3 4 
    cout<< endl;
}


template<typename func>
void checkExtension(func f, std::vector<int> DeviceRAM) {
    for(auto i : DeviceRAM) {
        if(f(i))
            cout<< i << " ";
    }
}
void checkDeviceCapability() {
    std::vector<int> v{6,4,6};

    checkExtension( [](int x) {return (x > 4); }, v);
    cout<<endl;
}

int main( void ) {
    usingLambda();
    checkDeviceCapability();
    return 1;
}