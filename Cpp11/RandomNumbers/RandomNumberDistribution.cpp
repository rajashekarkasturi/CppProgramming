#include<iostream>
#include<random>
#include<chrono>
using std::cin;
using std::cout;
using std::endl;

int main() {

    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();

    std::default_random_engine __engine3(seed);
    cout << __engine3 << endl;
    //But only generates the values between one range to another that is [__engine.min(), __engine.max()]

    //Range: [0: 5]
    cout << __engine3() % 6 << endl << endl;
    // 1. Bad quality of randomness
    // 2. Can only provide uniform distribution

    std::uniform_int_distribution<int> distr(0, 5); //[0, 5] both inculded special case
    cout << distr(__engine3) << endl;

    std::uniform_real_distribution<double> distr_double(0, 5); //[0, 5) 
    cout << distr_double(__engine3) << endl;

    std::poisson_distribution<int> distr_poisson(1.0); // mean 
    cout << distr_poisson(__engine3) << endl;    

    cout << "Normal Distribution: " << endl;
    std::normal_distribution<double> distribution_normal(10.0, 6.0);
    std::vector<int> new_vector(20);

    for(int i = 0 ; i < 800 ; i++) {
        int num = distribution_normal(__engine3); // convert double to int
        if( num >=0 && num <20)
            new_vector[num]++;  //
    }

    for(int i = 0 ; i < 20 ; i++) {
        cout << i << ": " << std::string(new_vector[i], '*') << endl;
    }

}