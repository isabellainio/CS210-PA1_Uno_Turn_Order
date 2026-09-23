1. In LinkedList::deleteFront(), why does it take two separate delete calls instead of one?
Name exactly what each one frees, and name the two new calls back in the program responsible
for putting them on the heap in the first place.

The first delete frees the T object stored in doomed->data, 
such as the int created by new int(10) or the Data object created by new Data(1, "Alice"). 
The second delete frees the Node<T> object created by new Node<T>(value) inside addFront().
Both objects are on the heap, so both need to be deleted separately.

2. ArrayList never had a destructor before today. Explain, in your own words, why switching
   from T data[CAPACITY] to T* data [CAPACITY] is what made a destructor necessary, and what
   would happen if you forgot to write one. Would you get a compiler error? Why or why not?

When the array stored values using T data[CAPACITY], the values were automatically cleaned up when
the ArrayList object was destroyed. After changing it to T* data_[CAPACITY], the array stores
pointers to objects created separately on the heap, so the destructor must manually delete those
objects. If the destructor were missing, the program would still compile because C++ does not
automatically report this as an error exactly, but the heap objects would remain allocated 
and cause potential leaks of memory.

3. search() and addFront() both take a T*, but they treat that pointer completely differently.
   Explain the difference in terms of ownership: which one is allowed to delete what you hand it,
   and which one is never allowed to?

addFront() takes ownership of the pointer it receives, so the list is responsible
for deleting that object later. search() only temporarily looks at the object through its
pointer and must never delete it. For example, pointers created with new are passed to
addFront(), while the address of the stack variable, such as &key, can be passed onto search().

4. You swapped LinkedList<T> for ArrayList<T> inside makeList() and reran main.cpp without
   changing a single line there. What two mechanisms, by name, made that possible?

The two mechanisms were inheritance through the List<T> abstract base class and virtual functions.
Both ArrayList<T> and LinkedList<T> implement the same interface, so a List<T>* or 
unique_ptr<List<T>> can call the correct version at runtime. The makeList() template selects which 
list type is created.

5. Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have
   thought to add on your own (explicit, override, virtual, const, or any other). Describe, in
   your own words and without copying the guide’s wording, the smallest example you can think
   of where leaving it out would cause a real problem.

The override keyword was useful because it makes the compiler check that a derived
class method actually matches a virtual method in the base class.
For example, if I accidentally wrote print() without the required const, the method
would not correctly replace List<T>::print() const. Without override, the program
might compile while using the wrong/unintended method and make the mistake harder
to find.