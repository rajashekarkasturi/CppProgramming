#include<iostream>
#include<memory>

class A {
    int num[1000000000L];
    std::new_handler originalHandler;
    public:
    static void NoMemForAlloc() {
        std::cerr << "No more memory " << std::endl;
        std::set_new_handler(originalHandler);  // Restore old handler
        throw std::bad_alloc;
    }

    void* operator new(std::size_t size) throw(std::bad_alloc) {
        auto origHandler = std::set_new_handler(NoMemForAlloc);
        void* ptr = ::operator new(size);   //call global operator new
        std::set_new_handler(originalHandler);  //Restore old handler
        return ptr;
    }

};