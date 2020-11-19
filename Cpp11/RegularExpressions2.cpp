#include<iostream>
#include<regex>
#include<string>

using std::regex;
using std::cin;
using std::cout;
using std::endl;


void grepRegularExpression() {
    std::string str;
    cout<<"Enter the string"<<endl;
    cin>>str;
    std::regex pattern("^abc.+", std::regex_constants::grep);
    //regex_constants::icase is used for case sensitive characters also
    //std::regex_constants::grep (particular grammar)
    
    //pattern("^abc.+") => Matched(abcd+, abcr+) => Not Matched(abc,abcd)
    
    bool match = std::regex_match(str, pattern);
    cout<<  (match ? "The string is Matched" : "Not Matched") << endl;
}

void subMatchExtractions() {
    
    std::string str;
    cout<<"Enter the string"<<endl;
    cin>>str;
    std::smatch m;
    std::regex pattern2("([[:w:]]+)@([[:w:]]+)\\.com"); //divided into groups for extractions
    
    bool found = std::regex_search(str, m, pattern2);

    cout << "m.size() " << m.size() << endl;
    for(int n = 0 ; n < m.size(); n++) {
        cout << "m[" << n << "]: str()=" << m.str(n) << endl;
    }

    //Enter the string
    //abc@gmail.com
    //m.size() 3
    //m[0]: str()=abc@gmail.com
    //m[1]: str()=abc
    //m[2]: str()=gmail

    
}

void IterationRegex() {
    std::string str = "abc@gmail.com;   abcdef@gmail.com;; abcd@gmail.com";

    std::regex pattern2("([[:w:]]+)@([[:w:]]+)\\.com"); //divided into groups for extractions

/*
    std::smatch m;
    cout << "m.size() " << m.size() << endl;
    for(int n = 0 ; n < m.size(); n++) {
        cout << "m[" << n << "]: str()=" << m.str(n) << endl;
    }
    //m.size() 3
    //m[0]: str()=abc@gmail.com
    //m[1]: str()=abc
    //m[2]: str()=gmail
*/

    std::sregex_iterator start(str.cbegin(), str.cend(), pattern2);
    std::sregex_iterator end;
    for(; start!=end; start++) {
        cout<< "Matched: "<<start->str(0) << endl;
        cout<< "User Name: "<<start->str(1) << endl;
        cout<< "Domain: "<<start->str(2) << endl;
        cout<<endl;                
    }

}

void RegexTokenIterator() {
    std::string str = "abc@gmail.com;   abcdef@gmail.com;; abcd@gmail.com";

    std::regex pattern2("([[:w:]]+)@([[:w:]]+)\\.com"); //divided into groups for extractions    
    
    std::sregex_token_iterator start(str.cbegin(), str.cend(), pattern2, -1);    //Zero indicates the first group, 1 the second the group
    // -1 indicates the group not matched with the regular expression
    
    
    std::sregex_token_iterator end;
    for(; start!=end; start++) {
        cout<< "Matched: "<<start->str() << endl;
        cout<<endl;                
    }

}

void RegexReplace() {
    std::string str = "abc@gmail.com;   abcdef@gmail.com;; abcd@gmail.com";

    std::regex pattern2("([[:w:]]+)@([[:w:]]+)\\.com", std::regex_constants::icase); //divided into groups for extractions    

    cout << std::regex_replace(str, pattern2, "$0 is on $2") << endl;
    //$0, $1, $2 are the positional parameters of the groups divided
    //Output:
    //abc@gmail.com is on gmail;   abcdef@gmail.com is on gmail;; abcd@gmail.com is on gmail    

    cout << std::regex_replace(str, pattern2, "$0 is on $2",std::regex_constants::format_no_copy) << endl;
    //Output:
    //abc@gmail.com is on gmailabcdef@gmail.com is on gmailabcd@gmail.com is on gmail

    cout << std::regex_replace(str, pattern2, "$1 is on $2", std::regex_constants::format_no_copy|std::regex_constants::format_first_only) << endl;    
    //Only the first match is considered as a match
    //Output:
    //abc is on gmail

}

int main() {


    //grepRegularExpression();
    //subMatchExtractions();           
    //IterationRegex();
    //RegexTokenIterator();
    RegexReplace();
    return 1;
}