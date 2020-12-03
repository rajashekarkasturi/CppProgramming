# C++ Key word: Using
1.  using directive: to bring all namespace members into current scope
        using namespace std;

2.  using declaration
        a. Bring one specific namespace member to current scope.
        b. Bring a member from base class to current class's scope.
    using std::cout;
    cout << "hello";

* Anonymous namespace is one with not having any name

namespace {
    void h() { std::cout << "h()\n";    }
}
int main() {
    h();
}

*Has advantages over static functions*


# Koenig Lookup

Extends the name search scope of the function parameter defined.

with namespaces:
current scope => next enclosed scope => ... => global scope

To override the sequence:
1. Qualifier or using declaration
2. Koenig lookup

With Classes:
current class scope => parent scope => ... => global scope

To override the sequence:
    -Qualifier or using declaration

Namehiding
