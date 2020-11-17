#include<iostream>
using std::cout;
using std::endl;


//User defined Literals
constexpr long double operator"" _Hz(long double x) { return x; }
constexpr long double operator"" _KHz(long double x) { return 10*10*10*x; }
constexpr long double operator"" _MHz(long double x) { return 10*10*10*10*10*10*x; }
constexpr long double operator"" _GHz(long double x) { return 10*10*10*10*10*10*10*10*10*x; }
int main( void ) {
    //C++ 99
    //long double frequency_of_processor  = 2.5; // GHz/MHz/KHz?

    //This is why we need user_defined literals
    long double frequency_of_processor  = 2.5_Hz;
    cout << frequency_of_processor <<endl;

    long double frequency_of_processor1  = 2.5_KHz;
    cout << frequency_of_processor1 <<endl;
    
    long double frequency_of_processor2  = 2.5_MHz;
    cout << frequency_of_processor2 <<endl;    
    
    long double frequency_of_processor3  = 2.5_GHz;
    cout << frequency_of_processor3 <<endl;
    return 1;
}
    //Output
    //2.5
    //2500    
    //2.5e+006
    //2.5e+009


