# Resource Acquisition is Initialization (RAII)

* Use Objects to manage resources:
    memory, hardware device, network handle, etc.


Mutex_t mu = MUTEX_INITIALIZER;

void function() {
    Mutex_lock( &mu );
        ....    // Do a bunch of things
    Mutex_unlock( &mu );    //will this line always be executed?
}

*NOTE: What if there is exception after the mutex is locked. It leads to forever lock of the mutex*


/-----------Solution-------------/

class Lock {
    private:
        Mutex_t* m_pm;
    public:
        explicit Lock(Mutex_t *pm) {    
            Mutex_lock(pm);
            m_pm = pm;
        };
        ~Lock() { 
            Mutex_unlock(m_pm); 
        };
}

void function() {
    Lock LockObj(&mu);
    .....
}   //The mutex will always be released when mylock is destroyed from stack


//*
# Conclusion:
* The only code that can be guaranteed to be executed after exceptoin is thrown are the destructor of objects residing on the stack.

* Resource management therfore needs to be tied to the lifespan of suitable objects in order to gain automatic deallocation and reclamation.
*//



/* Note 1:
    Another good example of RAII: tr1:shared_ptr
*/

int function_a() {
    std::tr1::shared_ptr<A> pd(new A());
}   // The dog is destructed when pd goes out of scope (no more pointer 
    // points to pd)

/* Note 2:
    Don't combine storing objects in shared pointer with other statements.
*/


/* Note 3:
   What happens when resource management object is copied?
*/
    Lock L1(&mu);
    Lock L2(L1);
    //Usually mutex is mutually exclusive so it cannot be shared by multiple clients

    Disallow Copy Constrcutor and Copy Assigment operator from being copied.

/* Solution 1:
 * Prohibit copying. To see how to disallow copy constructor and copy
 * assignemtn operator from being used.
 * Disallow Compiler Generated Functions.
 */

/* Solution 2:
 * Reference-count the underlying resource by using tr1::shared_ptr
*/ 

template<class Other, class D> shared_ptr(Other *ptr, D deleter);

//The default value for D is "delete", e.g.:
    std::tr1::shared_ptr<A> pd(new A())