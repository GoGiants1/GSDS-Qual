#include <iostream>
#include <vector>

using namespace std;

template <typename T>  // class template
class SimpleVector {
public:
    T *array;
    int size;
    int capacity;

    SimpleVector(int initialCapacity): size(0), capacity(initialCapacity){
        array = new T[capacity];
    }

    ~SimpleVector() { delete[] array; }

    void resize() {
        capacity *= 2;
        T *newArray = new T[capacity];
        for (int i=0; i<size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

    int getSize() const { return size; }

    void addElement(T element) {
        if (size==capacity) { resize(); }
        array[size] = element;
        size++;
    }

    void deleteLastElement() {
        size--;
    }

    // Operator Overloading
    T& operator[] (int index);
    SimpleVector operator+ (SimpleVector& rhs);
    SimpleVector& operator+=(SimpleVector& rhs);
    SimpleVector& operator++();
    SimpleVector operator++(int);
    // SimpleVector& operator<<(const T& element);
    bool operator==(SimpleVector& rhs);
    bool operator<(SimpleVector& rhs);
    operator bool() const;
    T* begin() { return array; }
    T* end() { return array + size; }
};

template <typename T>
T& SimpleVector<T>::operator[] (int index) {
    return array[index];
}

template <typename T>
SimpleVector<T> SimpleVector<T>::operator+(SimpleVector& rhs) {
    SimpleVector<T> result(size);

    for (int i=0; i<size; ++i) {
        result.addElement(array[i] + rhs[i]);
    }
    return result;
}

template <typename T>
SimpleVector<T>& SimpleVector<T>::operator+=(SimpleVector& rhs) {
    for (int i=0; i<size; ++i) {
        array[i] += rhs.array[i];
    }
    return *this;
}

template <typename T>
SimpleVector<T>& SimpleVector<T>::operator++() {
    for (int i=0; i<size; ++i) {
        ++array[i];
    }
    return *this;
}

template <typename T>
SimpleVector<T> SimpleVector<T>::operator++(int) {
    SimpleVector<T> temp(size);
    for (int i=0; i<size; ++i) {
        temp.addElement(array[i]);
        ++array[i];
    }
    return temp;
}

template <typename T>
SimpleVector<T>& operator<<(SimpleVector<T>& lhs, SimpleVector<T>& rhs) {
    for (int i=0; i<rhs.size; ++i) {
        lhs.addElement(rhs[i]);
    }
    return lhs;
}

template <typename T>
bool SimpleVector<T>::operator==(SimpleVector<T>& rhs) {
    if (size!=rhs.size) return false;
    for (int i=0; i<size; ++i) {
        if (array[i] != rhs[i]) return false;
    }
    return true;
}

template <typename T>
bool SimpleVector<T>::operator<(SimpleVector<T>& rhs) {
    return size < rhs.size;
}

template <typename T>
SimpleVector<T>::operator bool() const {
    return size > 0;
}

int main() {
    SimpleVector<int> *intVecPtr = new SimpleVector<int>(10);  // class pointer

    intVecPtr -> addElement(10);
    intVecPtr -> addElement(20);
    intVecPtr -> addElement(30);
    intVecPtr -> deleteLastElement();

    for (auto i=0; i < intVecPtr->size; ++i) {
        cout << intVecPtr->array[i] << " ";
    }
    cout << endl;

    delete intVecPtr;
    
    return 0;
}