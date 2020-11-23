#include<iostream>
#include<string>
#include<tuple>
#include<map>
using std::cin;
using std::cout;
using std::endl;

std::tuple<std::string, int> getValues()  {
    return std::make_tuple("Realme",4);
}


int main(void) {
    struct Mobile {
        std::string _mobile_name;
        int RAM;
    }m1;  

    std::tuple<std::string, int> mobile_tuple; 
    mobile_tuple = std::make_tuple("Samsing" ,6) ;

    cout << m1._mobile_name << m1.RAM << endl; //clearly emphasizes what we are doing and accessing (Readable) 
    cout << std::get<0>(mobile_tuple) << std::get<1>(mobile_tuple) << endl;

    //Suppose we want to return something as group from a function we can use tuple
    //As a one-time only structure to transfer a group of data;
    
    std::string _mobile_name;
    int RAM;
    std::tie(_mobile_name, RAM) = getValues();


    //making comparision
    std::tuple<int, int, int> t1, t2,t3; //Hours, minutes, seconds
    if(t1 > t2)
        cout << "Time1 is a later time";


    // Multiple index map
    std::map< std::tuple<int, std::string, int>, std::string > new_map;
    new_map[std::make_tuple(6, "Samsung s20fe", 8)] = "The new 2020 Edition";
    //we can also create Hashtables

    //swapping the data in between   
    int a=1,b=2,c=3;
    std::tie(c,b,a) = std::make_tuple(a,b,c);
    
    return 1;
}