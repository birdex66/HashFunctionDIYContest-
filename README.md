# HashFunctionDIYContest-

have been testing some different hash functions with an emphasis on 
- alphabetical order
- load factor

new idea:
- we have a hashtable with a array of linked lists
- reimplement the linked lists and hashtable as classes that have a length variable
    - linked lists length - number of slots used, pref under or at load factor
    - hashtable length - number of slots
- a hash function that uses the parameters for LF and length of linked list will be considered
- try to fit as many alphabetically similar sequences in one slot
    - if this isnt possible then add it to the next slot, checking length and iterating over if necessary
- for LF remember that it is ceil(n/k), so extra elements in a linked list can be accounted for
