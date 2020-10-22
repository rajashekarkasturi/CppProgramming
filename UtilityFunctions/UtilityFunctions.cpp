#include<iostream>
#include<cstdlib>
#include<string>

using std::cout;
using std::string;
using std::endl;


void conversion(void) {
    char *str = "hEHello";
    cout<<atof(str)<<endl;
    cout<<typeid(*str).name();

}

void searchitems(void) {
    /*  void *bsearch(const void *key, const void *buf, 
        size_t num, size_t size, 
        int (*compare) (const void *, const void *) );
    */
    long a= -10L;
    cout<< labs(a);
}


int main(void) {
    searchitems();
    return 0;
}