#ifndef SAFEARRAY_H
#define SAFEARRAY_H

using namespace std;

template <typename T>
class SafeArray {

protected:
    T *storage;
    int count;

public:
    SafeArray();
    SafeArray(int);
    virtual ~SafeArray(void);
    virtual T& operator[] (int) throw(out_of_range);
};

// default constructor
template <typename T>
SafeArray<T>::SafeArray () : storage(NULL), count(0) {}

// single param constructor
template <typename T>
SafeArray<T>::SafeArray (int count) : storage(new T[count]), count(count) {}

// destructor
template <typename T>
SafeArray<T>::~SafeArray(void) {
    delete [] this->storage;
}

// overloaded [] operator
template <typename T>
T& SafeArray<T>::operator[] (int index) throw (out_of_range) {

    if (index < 0) {
        throw out_of_range("Index is below 0");
    }

    if (index >= this->count) {
        throw out_of_range("Index is too high");
    }

    return this->storage[index];
}


#endif
