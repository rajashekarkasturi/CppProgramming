## Struct v/s Class

By default struct are **public**. Here, Structs provides the same functionality as a Class.

In c++ there are present for one of a reason to have backwards compatibility with C.

### Difference is with Usage
* Structs are used for **POD**( Plain old Data ).(Ex: A Vector structure binding two values together) where is not much functionality.


## Static in C++
Depending on the context if it defined outside of the class or struct, then linkage of that symbol that is declared as static is going to be internal to that translational unit which we defined it in.
- whereas a static variable which we defined inside of a class is going to share its memory across all it's instances of that class.

Three cases here(Static outside of a class or struct).
- **If a variable is static declared in a cpp program then it is refered or visible in it's translational unit only(Not visible to other Cpp programs)**.
- If there are two Global variables declares in two seperate files with the same name, then there will be a linking error mentioning(Already that variable is present.)
- To resolve the above issue, we generally mention extern keyword before a variable inorder to get that particular variable's data which is stored externally in other Cpp program.


## Enums
giving names to a value to make more readable.

## Virtual Functions
Come into picture via dynamic dispatch, Which compiles into typically implemented **vtables**. Contains a table of mapping of all the virtual functions that are base class and map them to the correct overriden function at runtime.
### Runtime Costs(Minimal impact unless you are using embedded systems)
* Additional memory inorder to store that Vtables to dispatch to the correct function.
* and also includes the member pointer that actually points to the vtable.
* so every time we call a virutal function these steps come into picture. vptr --> vtable.

## Pure virtual.
* Interface consists of pure virutal functions or unimplemented methods.
* Unable to instantiated.

## string literals
are always stored in Read only memory.

## const
```	
    const int* a = new int ; //contents cannot be modified
	int const* a = new int; //contents cannot be modified.
	int* const a = new int; //Refernce cannot be modified
    const int* const a = new int; //Both reference and contents cannot be modified.
```


## Lambda Functions
In Lambada functions, whenever  we pass a value with the captures, we cannot modify the value inside the body directly, Inorder to do so
we need to use the keyword **mutable**.

```
int a = 5;
auto lambda  = [=]() mutable { a = 6 ; std::cout << a << std::endl; };
```

