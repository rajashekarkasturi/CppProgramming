#include<iostream>

namespace A
{
    struct X{};
    void g(X) { std::cout << " Calling A::g()\n";}
    void g() { std::cout << "Calling A::g() \n";    }

} // namespace A

int main(void) {
    A::X x1;
    g(x1); //ADL //here the type of x makes us search g in the namespace of A.
    //g(); Error
    


//---------------1. Practical Reason-----------
    std::cout << "Hi" << std::endl; //Calls std::operator<<
    //std::cout std::<< "Hi" << std::endl;  // calls std::operator<<

    std::operator<<(std::cout, "hi");

    return 0;
}


//---------------2. Theoretical Reason:---------
namespace D {
    class C{
        public:
        virtual void f() = 0;
        virtual void g() = 0;
    };
    void h(C);
    std::ostream& operator<<( std::ostream&, const C&);
    //Can be the members of C
}

void j(C);

/* Definition of Class:
    A class describes a set of data, along with the functions that operate on that data.
*/

/* 
 * Engineering Principle:
 * 1. Function's that operate on class C and in a same namespace with C are part
 *      of C's interface
 * 2. Functions that are part of C's interface should be in the same
 *      namespace as C.
 */

int main() {
D::C c;
c.f();
h(c);
}

