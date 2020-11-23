#include<iostream>
#include<string>
#include<regex>
using std::cin;
using std::cout;
using std::endl;

/*
Regular Expression: Provides a specific pattern that provides concise and flexible means
*/
void basic_match() {
    std::string str;
    cin>>str;
    std::regex pattern("Jun", std::regex_constants::icase);
    //regex_constants::icase is used for case sensitive characters also

    bool match = std::regex_match(str, pattern);
    cout<<  (match ? "The string is Matched" : "Not Matched") << endl;

}

void dotQStarPlusMatch() {
    std::string str;
/*
    cout << "Enter the String for last character with dot: \n";
    cin >> str;
    std::regex pattern("Jun.", std::regex_constants::icase);
    //. Any character except newline

    bool match = std::regex_match(str, pattern);
    cout<<  (match ? "The string is Matched" : "Not Matched") << endl;
    
    cout << "Enter the String for last character with Question mark: \n";
    cin >> str;
    std::regex pattern1("Jun?", std::regex_constants::icase);
    // ?  (Zero or 1 preceding character )
    //Matching Ju, Jun
    //Not mached June, Jun?

    bool match1 = std::regex_match(str, pattern1);
    cout<<  (match1 ? "The string is Matched" : "Not Matched") << endl;    
    
    cout << "Enter the String for last character with star: \n";
    cin >> str;
    std::regex pattern2("Jun*",std::regex_constants::icase);
    //. Any character except newline
    //Here Ju with n(0,1,2,3,4,5)

    bool match2 = std::regex_match(str, pattern2);
    cout<<  (match2 ? "The string is Matched" : "Not Matched") << endl;
    //Matched ju, junnn,jun
    //Not Matched j


    cout << "Enter the String for last character with +: \n";
    cin >> str;
    std::regex pattern3("Jun+",std::regex_constants::icase);
    //One or more preceding character
    
    bool match3 = std::regex_match(str, pattern3);
    cout<<  (match3 ? "The string is Matched" : "Not Matched") << endl;
    //Matched Junn, Jun, jun
    //Not Matched Ju

    cout << "Enter the String, for last character within []: \n";
    cin >> str;
    std::regex pattern4("Jun[e]",std::regex_constants::icase);
    //Any character inside the square brackets
    //we can also manipulate Jun[e]+, June[e]*
    //[^e] any character not ending we e in [] can match
    //[cd]{3,} 3 or more characters of cd minimum
    // a|b , here a or b can be matched
    // regex pattern("(abc)de+\\1");    //() are considered as group so \1 means group 1 time
    //abcdeabc -> matches


    bool match4 = std::regex_match(str, pattern4);
    cout<<  (match4 ? "The string is Matched" : "Not Matched") << endl;
    //Matched June, june
    //Not Matched Junee, jun 
*/
    
}

void emailMatcher() {
    std::string email;
    cout<<"Enter the email: ";
    cin>>email;

    std::regex email_pattern("[[:w:]]+@[[:w:]]+\\.com"); //[[:w]] word character: digit, number, or underscore

    bool email_match = std::regex_match(email, email_pattern);
    
    cout << (email_match? "It is an Email" : "Not an email") << endl;
}

void searchingSubstring() {
    std::string str;
    cin>>str;
    std::regex pattern("nov", std::regex_constants::icase);
    //regex_constants::icase is used for case sensitive characters also

    bool match = std::regex_search(str,pattern);
    //search for a particular pattern of regex in the string.
    cout<<  (match ? "Pattern found" : "Pattern not found") << endl;
    //to search at beginning (^abc)
    //to search at ending (abc$)
}
int main() {

    while(true) {
        //basic_match();
        //dotQStarPlusMatch();
        //emailMatcher();
        searchingSubstring();
    }
    return 1;
}