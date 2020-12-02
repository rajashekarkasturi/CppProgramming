/*
    Koenig Lookup
*/
#include<iostream>

//Example 1:

/*

namespace A
{
    struct X {};
    void g(X) { std::cout << " Calling A::g()\n";}
} // namespace A

int main() {
    A::X x1;
    A::g(x1);   //Output -> Calling A::g()
    g(x1);  //Output -> Calling A::g()---------Koenig Lookup, or Argument Dependent LookUp(ADL)
}
*/

//Example 2:

/*
class C{
    public :
        struct Y{};
        static void h(Y) {
            std::cout << "Calling C::h() \n";
        }
};

int main() {
    C::Y y;
    h(y);   // here it will not invole h from Class C, even though h is static
        // ADL only works for namespaces
    return 0;
}
*/


//Example 3:


/*
namespace A
{
    struct X {};
    void g(X) { std::cout << " Calling A::g()\n";}
} // namespace A

namespace C
{
    void g(A::X) { std::cout << "Calling C::g() \n";    }
    void j() {
        A::X x;
        g(x);
    }
} // namespace C

int main() {
    C::j(); //Error :call of overloaded 'g(A::X&)' is ambiguous
        //From rule of ADL it can also see the g() function of A namespace
}
*/

/* Solution
    Make Namespace C as a Class   
    First Preference is given inside the class to check appropriate function
    Second is given for namespace heirarchy
*/


//Example 4: Name hiding in namespaces

/*
namespace A
{
    void g(int) { std::cout << " Calling A::g()\n";}

    namespace C
    {
        void g() { std::cout << "Calling C::g() \n";    }
        void j() { 
            g(8);
        }
    } // namespace C

} // namespace A

int main(void) {
    A::C::j();  //Error
    //Overcome by introducing the using key word declaration
    //using A::g; upon g(8);

    return 0;
}
*/

namespace A
{
    struct X{};
    void g(X) { std::cout << " Calling A::g()\n";}

    namespace C
    {
        void g() { std::cout << "Calling C::g() \n";    }
        void j() {
            X x;
            g(x);
        }
    } // namespace C

} // namespace A

int main(void) {
    A::C::j();  //Output : Calling A::g();
    //No error because, it check the x in the X space
    return 0;
}


