# Demystifying Operator new/delete

A* ptr = new A()

->Steps:
1. Operator new is called to allocate memory.
2. A's constructed is called to create A.
3. If step 2 throws an exception, call operator delete to free the memory allocated in step1.

delete ptr;

->Steps:
1. A's destructor is called.
2. operator delete is called to free the memory.


* Why do we want to customize new/delete
    * Usage error detection:
        *   Memory leak detection/garbage collection.
        *   Array index overrun/underrun.
    * Improve efficiency: 
        * Clustering related objects to reduce page fault.
        * Fixed size allocation (good for application with many small objects)
        * Align similar size objects to same places to reduce fragmentation.
    * Perform additional tasks:
        * Fill the deallocated memory with 0's - security
        * Collect usage statistics.
