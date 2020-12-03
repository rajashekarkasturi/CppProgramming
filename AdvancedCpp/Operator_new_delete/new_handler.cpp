//Define your own New-handler

/*
 * 1. What is new-handler
 * 
 * New handler is a function invoked when operator new failed to allocate
 * memeory. It's purpose is to help memeory allocation to succeed.
 * set_new_handler() installs a new handler and returns current new handler.
 * 
 */
#include<iostream>
#include<memory>

void* operator new(std::size_t size) throw (std::bad_alloc) {
    while(true) {
        void* pMem = std::malloc(size); // Allocate memory
        if(pMem)
            return pMem;    //Return the memory if successful
        
        std::new_handler Handler = std::set_new_handler(0);   // Get new Handler
        std::set_new_handler(Handler);

        if(Handler)
            (*Handler)();       //Invoke new handler
        else 
            throw std::bad_alloc();  //If new handler is null, throw exception
    }
}

/*
 * So the new-handler must to do one of the following things:
 * 1. Make more memory available.
 * 2. Install a different new-handler
 * 3. Uninstall the new-handler (passing a null pointer).
 * 4. Throw an exception bad_alloc or its descendent.
 * 5. Terminate the program.
 */


/*
void Sample() {
    int *ptrBig = new int[10000000000L];
    delete[] ptrBig;    
}//Output:
//error: size '10000000000' of array exceeds maximum object size '2147483647'
//     int *ptrBig = new int[10000000000L];

*/


void NoMoreMemory() {
    std::cerr << "Unable to allocate memory " <<    std::endl;
    abort();
}


int main() {
    std::set_new_handler(NoMoreMemory);
    int *ptrBig2 = new int[10000000000L];
    delete[] ptrBig2;
}

