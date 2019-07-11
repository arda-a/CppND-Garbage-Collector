// This class defines an element that is stored
// in the garbage collection information list.
//
template <class T>
class PtrDetails
{
  public:
    unsigned refcount; // current reference count
    T *memPtr;         // pointer to allocated memory
    /* isArray is true if memPtr points
to an allocated array. It is false
otherwise. */
    bool isArray; // true if pointing to array
    /* If memPtr is pointing to an allocated
array, then arraySize contains its size */
    unsigned arraySize; // size of array
    // Here, mPtr points to the allocated memory.
    // If this is an array, then size specifies
    // the size of the array.

    PtrDetails(T* t, unsigned size = 0) : memPtr(t), arraySize(size)
    {
        // TODO: Implement PtrDetails
        isArray = size > 0;
    }
};
// Overloading operator== allows two class objects to be compared.
// This is needed by the STL list class.
template <class T>
bool operator==(const PtrDetails<T> &obj1,
                const PtrDetails<T> &obj2)
{
    return *(obj1->memPtr) == *(obj2->memPtr) &&
            obj1->refcount == obj2->refcount &&
            obj1->arraySize == obj2->arraySize;
}