/*
List : Bidirectional Linear List, Supports random access, Can be accessed front to back or back to front

List Template Specification: 
    template <class T, class Allocator = allocator <T> > class list

*/
#include<cstdlib>
#include<iostream>
#include<list>
using std::list;
using std::cout;
using std::cin;
using std::endl;

class student {
    int id, m1,m2;
    int sum;

    public :
    student() { m1 = 0;  m2  = 0; sum = 0; }
    student(int i, int a, int b) {
        id = i; 
        m1 = a;
        m2 = b;
        sum = m1 + m2;
    }

    int getTotal() { return sum;}

    friend bool operator<(const student &o1, const student &o2);
    friend bool operator>(const student &o1, const student &o2);
    friend bool operator==(const student &o1, const student &o2);
};

bool operator<(const student &o1, const student &o2){
    return o1.sum < o2.sum;
};
bool operator>(const student &o1, const student &o2){
    return o1.sum > o2.sum;
};
bool operator==(const student &o1, const student &o2){
    return o1.sum == o2.sum;
};


void display(list<int> T) {
    for(auto i :T) {
        cout<< i << " ";
    }
    cout<<endl;
} 

void GeneralListOperations(void) {
   
    list<int> l1;

    cout<<"Entering elements into the list at the end \n";
    l1.push_back(5);
    l1.push_back(6);
    cout<<"Reference to the last entered element in the list: "<<l1.back()<<endl;

    cout<<"Entering elements into the front of the list\n";
    l1.push_front(4);
    l1.push_front(3);
    cout<<"Reference to the last element in the list: "<<l1.back()<<endl;

    cout<<"Reference to the first entered element in the list: "<<l1.front()<<endl;
    cout<<"Size of the list: "<<l1.size()<<endl;

    cout<<"Elements in the list: \n"<<endl;
    display(l1);

    cout<<"Removing element 5 \n";
    l1.remove(5);
    cout<<"Total List\n";
    display(l1);

    cout<<"Inserting Elements\n";
    l1.push_back(1);
    l1.push_front(10);
    l1.push_back(6);
    l1.push_front(14);

    cout<<"Total Size of the list\n"<<l1.size()<<endl;
    display(l1);

    //sorting the list
    cout<<"Sorting the list l1 "<<endl;
    l1.sort();
    display(l1);


    l1.reverse();
    //Clearing the whole list
    /*
    cout<<"Erasing the list\n"<<endl;
    l1.clear();

    //Checking if the list is empty or not
    if(l1.empty()) {
        cout<<"The list is empty"<<endl;
    }    

    cout<<"The size of the list: "<<l1.size()<<endl;
    */
    //Creating iterator to the list
    list<int>::iterator p =l1.begin();
    
    while(p!= l1.end()) {
        cout<<*p<<" ";
        p++;
    }
    
    p = l1.begin(); 
    p = ++p ;
    list<int>::iterator q = l1.end(); 
    q = --q;
    l1.erase(p, q);

    //end()-1 points to the last element to the list
    cout<<endl<<l1.size()<<endl;
    display(l1);
    q = l1.end();
    q--;
    cout<<*q;    

}



int main(void) {
    

    //Creating a list of objects

    list<student> students1;
    list<student> students2;
    //Inputing the IDs
    for(int i = 0 ; i< 10 ; i++){   
        srand(5);
        students1.push_back(student(i, rand()%10 , rand()%10));
    }

    for(int i = 0 ; i < 10; i++ ) {
        srand(i+1);
        students1.push_back(student(i, rand() % 10 , rand() % 10));
    }

    list<student>::iterator m = students1.begin();
    list<student>::iterator n = students2.begin();

    for(int i = 0 ; i < 10 ; i++) {
        cout<<m->getTotal() <<" "<< n->getTotal()<<endl;
    }

    for(int i = 0 ; i < 10 ; i++) {
        if( *m < *n ) {
            cout<<"student 2 is Greater than student 1"<<endl;
        }
        else if( *m > *n) {
            cout<<" Student 1 is greater than student 2"<<endl;
        }
        else {
            cout<<"P and Q are equal "<<endl;
        }
    }

    return 0;
} 