<b>Core of STL has 3 foundational items : </b>
1. Containers: Objects that hold other objects
2. Algorithms: Act on Containers, means by which you will manipulate the contents of Containers.
3. Iterators: are objects that act, more or less, like pointers.

<b>Iterators</b>
Random Access: Store and retrieve values. Elements may be accessed randomly.
Bidirectional: Store and retrieve values. Forward and backward moving.
Forward: Store and retrieve values. Forward moving only.
Input: Retrieve, but not store values. Forward moving only.
Output: Store, but not retrieve values. Forward moving only

/* Reverse Iterators are either bidirectional or random-access iterators that move through a sequence in the reverse direction. Thus, if a reverse iterator points to the end of a sequence, incrementing that iterator will cause it to point to one element before the end.*/