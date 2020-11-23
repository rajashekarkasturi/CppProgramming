*Multiprocessing*
Process 1 (1-Thread)----Interprocess Communication----Process 2 (1-Thread)


--Here Interprocess Communication constitutes*
    Files
    Pipes
    Message Queues

Pros:
* Can run on a distributed system.


*Multithreading*
#Process 1 (Consists of Two or more threads)
Thread 1 ----Shared Memory---- Thread 2

-- A thread is considered as a lightweight process

Pros:
* Fast to start
* Low overhead

Cons:
* Difficult to implement
* Can't run on distributed system