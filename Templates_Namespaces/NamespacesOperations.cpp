#include<iostream>


namespace myNamespace {
    int upperbound;
    int lowerbound;

    class counter {
        int count;
    public :
        counter(int n) {
                if(n <= upperbound)
                    count = n;
                else
                    count = upperbound;    
            }

        void reset(int n) {
            if( n <= upperbound)
                count = n ;
        }

        int run() {
            if(count > lowerbound) return count--;
            else return lowerbound;
        }    
    };
}

void basicNamespace(void) {
    myNamespace::upperbound = 100;
    myNamespace::lowerbound = 0;
 
    myNamespace::counter obj(10);
    int i;

    do{
        i = obj.run();
        std::cout<< i << " ";
    } while(i > myNamespace :: lowerbound);
    std::cout<< std::endl;
    
   myNamespace::counter ob2(20);

    do {
        i = ob2.run();
        std::cout<< i << " ";
    }while(i > myNamespace::lowerbound);

    ob2.reset(100);

    myNamespace::lowerbound - 90;
    do{
        i = ob2.run();
        std::cout<< i << ' ';
    } while(i > myNamespace::lowerbound);

}


int main(void) {

    basicNamespace();
    return 0;
}