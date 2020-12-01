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