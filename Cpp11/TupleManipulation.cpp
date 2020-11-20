#include<iostream>
#include<string>
#include<tuple>
using std::cin;
using std::cout;
using std::endl;

int main( void ) {

    //pair of only two values
    std::pair<int, std::string> dual_pair = std::make_pair(23, "Hello");
    cout << dual_pair.first << " " << dual_pair.second << endl;


    //tuple is an extended pair
    std::tuple<int, std::string, int> triple_pair(21, "Good Morning", 12211);
    
    //get should have a compile time constant
    cout << std::get<0>(triple_pair) << " " << std::get<1>(triple_pair) << " " << std::get<2>(triple_pair) << endl;
    
    //get value return the reference
    std::string& str = std::get<1>(triple_pair);
    str = "Changed the value";
    cout <<"after altering the value: " << std::get<1>(triple_pair);
    

    std::tuple<int, char> dual_pair2;
    dual_pair2 = std::tuple<int, char> (97, 'a');
    dual_pair2 = std::make_tuple(21,'b');

    //Tuple can store reference but none of the STL containers can do

    std::tuple<int, char, int> new_tuple3 = std::make_tuple(1, 'a' , 2);
    int a;
    char b;
    int c;

    //std::make_tuple(std::ref(a), std::ref(b), std::ref(c)) = new_tuple3;
    std::tie(a, b, c) = new_tuple3;
    cout << endl << std::get<0>(new_tuple3) << endl;
    
    //concantenate two tuples

    auto new_tuple4 = std::tuple_cat(dual_pair2, new_tuple3);
    cout << std::get<0>(new_tuple4) << endl;
    cout << std::get<1>(new_tuple4) << endl;
    cout << std::get<2>(new_tuple4) << endl;
    cout << std::get<3>(new_tuple4) << endl;
    cout << std::get<4>(new_tuple4) << endl;


    // type traits
    cout<< std::tuple_size<decltype(new_tuple4)>::value << endl;
    std::tuple_element<2, decltype(new_tuple4)>::type d;
    cout<< d << endl; 
    return 1;
}
