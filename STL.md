<b>Core of STL has 3 foundational items : </b>
1. Containers: Objects that hold other objects
2. Algorithms: Act on Containers, means by which you will manipulate the contents of Containers.
3. Iterators: are objects that act, more or less, like pointers.

<b>Iterators</b>
<ul>
<li>Random Access( RandIter ): Store and retrieve values. Elements may be accessed randomly.
<li>Bidirectional( BiIter ): Store and retrieve values. Forward and backward moving.
<li>Forward( ForIter ): Store and retrieve values. Forward moving only.
<li>Input( InIter ): Retrieve, but not store values. Forward moving only.
<li>Output( OutIter ): Store, but not retrieve values. Forward moving only

-- Reverse Iterators are either bidirectional or random-access iterators that move through a sequence in the reverse direction. Thus, if a reverse iterator points to the end of a sequence, incrementing that iterator will cause it to point to one element before the end.

-- In addition to containers, algorithms, and iterators, the STL relies upon several other
standard components for support. Chief among these are allocators, predicates,
comparison functions, and function objects.

<h2> Container Classes </h2>
<table>
    <tr>
        <th>Container</th> 
        <th>Description </th>
        <th>Required Header </th>
    </tr>
    <tr>
        <td>bitset</td>
        <td>A set of bits. </td>
        <td>&ltbitset&gt</td>
    </tr>
    <tr>
        <td>deque</td>
        <td>A double-ended queue.</td>
        <td>&ltdeque&gt</td>
    </tr>
    <tr>
        <td>list</td>
        <td>A linear list.</td>
        <td>&ltlist&gt</td>
    </tr>
    <tr>
        <td>map</td>
        <td>Stores key/value pairs in which each key is associated with only one value.</td>
        <td>&ltmap&gt</td>
    </tr>
    <tr>
        <td>multimap</td>
        <td>Stores key/value pairs in which one key may be associated with two or more values</td>
        <td>&ltmap&gt</td>
    </tr>
    <tr>
        <td>multiset</td>
        <td> A set in which each element is not
necessarily unique.</td>
        <td>&ltset&gt</td>
    </tr>
    <tr>
        <td>priority_queue</td>
        <td>A priority queue.</td>
        <td>&ltqueue&gt</td>
    </tr>
    <tr>
        <td>queue </td>
        <td>A queue. </td>
        <td>&ltqueue&gt</td>
    </tr>
    <tr>
        <td>set</td>
        <td>A set in which each element is unique.</td>
        <td>&ltset&gt</td>
    </tr>
    <tr>
        <td>stack</td>
        <td>A stack.</td>
        <td>&ltstack&gt</td>
    </tr>
    <tr>
        <td>vector</td>
        <td>A dynamic array.</td>
        <td>&ltvector&gt</td>
    </tr>
</table>
