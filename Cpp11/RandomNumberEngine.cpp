#include<iostream>
#include<random>
#include<chrono>
using std::cin;
using std::cout;
using std::endl;


/* Random Engine:
 * Stateful generator that generates random values within predefined min and max
 * not truely random -- pseudorandom
 */


void print(std::default_random_engine dre) {
    for(int i = 0 ; i  < 10 ; i ++)
        cout << dre() << " ";
    cout<<endl;    
}


int main( void ) {

    std::default_random_engine __engine;

    cout<<"Minimum random: " << __engine.min() << endl;
    cout<<"Maximum random: " << __engine.max() << endl;

    cout << "Random Value " << __engine() << endl;
    cout << "Random Value " << __engine() << endl;

    std::default_random_engine __engine1;
    std::default_random_engine __engine2;

    print(__engine1);
    print(__engine2);

    //to generate a different sequence each and everytime we use seed to generate from steady_clock
    //seed determines the internal state of the engine
    
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();

    std::default_random_engine __engine3(seed);
    print(__engine3);


    return 0;
}