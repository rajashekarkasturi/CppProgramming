#include<iostream>
#include<regex>
using std::regex;
using std::cin;
using std::cout;
using std::endl;


int main(void ) {
    std::string password;
    cout << "Enter the Password: \n";
    cin >> password;
    if(password.length() < 14 )
        exit(1);
    else{        
        std::regex password_pattern("[a-z]*[@#]*[^123][^1234][^jan][^feb][^mar][^apr][^may][^jun][^jul][^aug][^sep][^oct][^nov][^dec][a-z]{10}*",std::regex_constants::icase);    
        bool password_match = std::regex_match(password, password_pattern);
        cout<<  (password_match ? "The string is Matched" : "Not Matched") << endl;
    }    
    return 1;
}