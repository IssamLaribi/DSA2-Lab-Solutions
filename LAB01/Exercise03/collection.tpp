#include "collection.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
void Collection<T>::resize() {
        int newCapacity = capacity * 2;
        T* newArr = new T[newCapacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }   
        delete arr;
        arr = newArr;
        capacity = newCapacity;
    }

template<typename T>
Collection<T>::Collection() {
    capacity = 10;
    size = 0;
    arr = new T[capacity];
}

template<typename T>
Collection<T>::Collection(int cap) {
    capacity = cap;
    size = 0;
    arr = new T[capacity];
}

template<typename T>
Collection<T>::~Collection() {
    delete[] arr;
}

template<typename T>
bool Collection<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
void Collection<T>::makeEmpty() {
    size = 0;
}

template<typename T>
void Collection<T>::insert(const T& x) {
    if (size == capacity) {
        resize();
    }
    arr[size++] = x;
}

template<typename T>
void Collection<T>::remove(const T& x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            return; // It will only remove the first element that equals x 
        }
    }
}

template<typename T>
bool Collection<T>::contains(const T& x) const {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) return true;
    }
    return false;
}

template<typename T>
void Collection<T>::display() const {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

