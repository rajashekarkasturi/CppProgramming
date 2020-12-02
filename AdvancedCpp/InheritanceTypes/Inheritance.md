# Public, Protected, Private Inheritance

class A {

};
class B_priv : private A {};
class B_prot : protected A {};
class B_pub  : public A {};

* They specify different access control from the derived class to the base class.

Access Control:
1. None of the derived classes can access anything that is private in A.
2. B_pub inherits public members of B as public and the protected members of A as protected
3. B_priv inherits the public and protected members of A as private.
4. B_prot inherits the public and protected members of A as protected.

Casting:
1. Anyone can cast a B_pub* to A*. B_pub is a special kind of A.
2. B_priv's members and friends can cast a B_priv* to A*.
3. B_prot's members, friends, and children can cast a B_prot* to A*

* Public inheritance: is-a relation, ex: B_pub is a kind of a A
* Private inheritance: similar to has-a relation.


*Summary:*
* 1. Precise definition of classes:
* 2. Don't override non-virtual functions;
* 3. Don't override default parameter values for virtual functions;
* 4. Force inheritance of shadowed functions.


*Types of Inheritance:*
* 1. Pure virtual public function - inherit interface only.
* 2. Non-virtual public function - inherit both interface and implementation.
* 3. Impure virtual public function - inherit interface and default implementation.
* 4. Protected function - inherit implementation only
* 
* As a software designer, it is very important to seperate the concepts of interface and implementation.


* Interface Inheritance:
1. Subtyping
2. Polymorphism
    [virtual void print() = 0;]

    * Pitfalls
        * Be careful of interface bloat
        * Interfaces do not reveal implementation.

* Implementation Inheritance
    * Increase code complexity.
    * Not encouraged.

public :
    void run() {    cout << "I am running "; }
    virtual void eat() {    cout <<"I am eating ";  }
protected:
    void sleep()    {cout << "I am sleeping " ; }

*Guidelines for Implementation Inheritance*
1. Do not use inheritance for code reuse, use composition.
2. Minimize the implementation in base classes. Base classes should be thin
3. Minimize the level of hierarchies in implementation inheritance.



# Code Reuse: Inheritance v/s Composition.

* Code reuse with Inheritance
class A {

};

class B : public A {

};

class C : public A {

};

* Code reuse with Composition

class TeamLead {

};
class Mentor {

};

class Employee1 : public Mentor {
    TeamLead* tl1;
};

class Employee2 : public Mentor {
    TeamLead* tl2;
};

* Code reuse: Composition is better than inheritance

1. Less code coupling between reused code and reuser of the code.
    * Child class automatically inherits ALL parent class's public members.
    * Child class can access parent's protected members.
        - Inheritance breaks encapuslation.

2. Dynamic Binding
    * Inheritance is bound at compile time.
    * Composition can be bound either at compile time or at run time. 
