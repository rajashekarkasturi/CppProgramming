#include <pthread.h>
#include <array>
#include <cassert>
#include <iostream>

// Dynamic initialization of pthread done by pthread_mutex_init(..)
// static init is done by ->
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


// Function that serves entry point for threads
// Return values and parameters are passed through void pointers

void *print_func(void *args)
{
    // Cast our argument back it's original type
    int *ID = static_cast<int *>(args);

    // Lock the mutex before printing
    pthread_mutex_lock(&lock);
    std::cout << "Print from thread: " << *ID << '\n';
    pthread_mutex_unlock(&lock);

    //We can call pthread_exit to kill the thread
    // Pass NULL if we don't care about the status code
    pthread_exit(NULL);

}

int main()
{
    //Create an array of 4 thread IDs and 4 threads
    std::array<int, 4> ids = {0, 1, 2, 3};
    std::array<pthread_t, 4> threads;

    //Create four threads with the print function as an entrypoint
    //Arguments:
    // 1. Address of thread object
    // 2. Thread attributes (NULL means default)
    // 3. Entrypoint (function pointer)
    // 4. void pointer to arguments.

    for(auto &id : ids)
    {
        pthread_create(&threads[id], NULL, print_func, static_cast<void*>(&id));
    }
    pthread_exit(NULL);
}