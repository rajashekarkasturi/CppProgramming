# Compiler Generated Functions
-   Complier silently writes 4 functions if they are not explicitly delcared:
1. Copy Constructor
2. Copy Assignment Operator
3. Destructor
4. Default Constructor (Only if there is no constructor declared).

*Note*
1. They are public and inline.
2. They are generated only if they are needed.

# Summary of Disallowing Functions

1. C++ 11: f() = delete
2. C++ 03: Declare the function to be private, and not define it.
3. Private destructor: stay out of stack