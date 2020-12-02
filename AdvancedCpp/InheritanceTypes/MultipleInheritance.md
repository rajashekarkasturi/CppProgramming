# Key takeaway
* Diamond Problem
* Making base classes Virtual while inherting
* Defining constructors in the most derived class
* Difficult to use but, what we it is intended to use
    *   Interface segregation principle
        Split large interfaces into smaller and more specific ones so that clients only need to know about the methods that are of interest to them.
    *  Pure Abstract Classes
       Abstract class:  A class has one or more pure virtual functions.

       Pure Abstract Classes:
       A class containing only pure virtual functions
        - no data
        - no concrete functions

-> Summary:
    1. Multiple Inheritance is an important technique, e.g. ISP
    2. Derive only from PACs when using Multiple Inheritance.