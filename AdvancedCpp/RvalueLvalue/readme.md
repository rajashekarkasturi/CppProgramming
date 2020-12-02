# Understanding Rvalue and Lvalue

* Why do I care?
1. Understand C++ construct, and decypher compiler errors or warnings.
2. C++ 11 introduced rvalue reference.

* lvalue - An object that occupies some indentifiable location in memory (Not register)
* rvalue - Any object that is not a lvalue.

*Summary*
* Every C++ expression yield either an rvalue or a lvalue
* If the expression has an identifiable memory address, it's lvalue; Otherwise, rvalue.