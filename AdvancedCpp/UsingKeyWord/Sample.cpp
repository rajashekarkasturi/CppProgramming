#include<iostream>

using std::cout;
using std::endl;

class A {
    public:
        void f(int a);
};

class B : private A {
    public :
        void g() {
            using namespace std;
            cout << "From B "<<endl;    //  case 1, local scope
        }
        void h() {
            using std::cout;    //  case 2.a local scope
            cout << "From B "<<endl;
        }
        using A::f; // case 2.b, class scope
        //usign namespace std;    //class scope illegal
};

//using A::f; illegal


class C{
    public:
        void f(int a) {

        }
};
class D: public C {
    public:
        void f();
};
class E: public C {
    public:
        using C::f;
        void f();
};

int main() {
    D d;
    //d.f(8); //will not work because of namehiding
    //inorder to use C::f we need to write using in Class D
    E e;
    e.f();
}
 
