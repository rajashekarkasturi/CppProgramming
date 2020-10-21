#include<iostream>
#include<functional>
#include<algorithm>
#include<list>

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::transform;
using std::negate;
using std::divides;
using namespace std;

void NegateAndDivides( void ){
    list<int> values;
    list<int> divisors;

    for(int i = 5 ; i < 55 ; i = i + 5)   values.push_back(i);
    for(int i = 1 ; i < 10 ; i++)    divisors.push_back(5.0);

    cout<<"Orginal Contents in List:\n";
    for(int x: values) {
        cout<<x<<" ";
    }
    list<int>::iterator p;

    //p = transform(values.begin(), values.end(), values.begin(), negate<int>());

    p = transform(values.begin(), values.end(), divisors.begin(), values.begin(), divides<int>());

    cout<<endl;
    for(int x: values) {
        cout<<x<<" ";
    }    

}

//Creating a new unary function object

class powersof : unary_function<int, int> {
    public:
        result_type operator() (argument_type i) {
            return (result_type) i*i*i;
        }
};

void UserDefinedFunctionObjectsUnary( void ) {

//we need to overload the operator() function

    /*Unary and Binary Functions*/

    /*
    template <class Argument, class Result> struct unary_function {
        typedef Argument argument_type;
        typedef Result result_type;
    };

    template <class Argument1, class Argument2, class Result>
    struct binary_function {
        typedef Argument1 first_argument_type;
        typedef Argument2 second_argument_type;
        typedef Result result_type;
    }
    */

    list<int> val;
    int i;
    
    for(i = 0 ; i < 10 ; i++ )  val.push_back(i);

    cout<<"Contents in the list:\n";
    for(auto j : val) {
        cout<<j<<" ";
    }
    cout<<endl;
    list<int>::iterator p;
    
    p = transform(val.begin(), val.end(), val.begin(), powersof());

    cout<<"Transformed Contents\n";
    for(int x : val) {
        cout<<x<<" ";
    }

}

// Usage of Binders
void UsageOfBinders( void ) {
    list<int> list2;
    list<int>::iterator p , endp;

    int i;

    for(i = 1; i < 20 ; i++) list2.push_back(i);

    cout<< "Original Sequence:\n";
    p = list2.begin();
    while (p != list2.end())
    {
        cout<< *p << " ";
        p++;
    } //1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
    cout<<endl;

    endp = remove_if(list2.begin(), list2.end(), bind2nd(greater<int>(), 8) );
    
    
    cout << "Resulting sequence:\n";
    p = list2.begin();
    while(p != endp) {
    cout << *p << " ";
        p++;    
    } //1 2 3 4 5 6 7 8
    cout<<endl;

    endp = remove_if(list2.begin(), list2.end(), not1(bind2nd(greater<int>(), 8) ));

    p = list2.begin();
    while(p != endp) {
    cout << *p << " ";
        p++;    
    } //9 10 11 12 13 14 15 16 17 18 19
    cout<<endl;


} 

int main(void) {

    NegateAndDivides();
    UserDefinedFunctionObjectsUnary();
    UsageOfBinders();
    return 1;
}
