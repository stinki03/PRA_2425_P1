#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

public:
    ListArray();
    ~ListArray();
    T operator[](int pos);

    // Declaración de la función friend como plantilla
    template <typename U>
    friend std::ostream& operator<<(std::ostream &out, const ListArray<U> &list);

    void insert(int pos, T e) override;
    void append(T e) override;
    void prepend(T e) override;
    T remove(int pos) override;
    T get(int pos) const override;
    int search(T e) const override;
    bool empty() const override;
    int size() const override;

private:
    void resize(int new_size);
};

// Definición de la función friend fuera de la clase
template <typename T>
std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
    out << "[";
    for (int i = 0; i < list.n; ++i) {
        out << list.arr[i];
        if (i < list.n - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

// Implementación de los métodos de ListArray
template <typename T>
ListArray<T>::ListArray() : max(MINSIZE), n(0) {
    arr = new T[max];
}

template <typename T>
ListArray<T>::~ListArray() {
    delete[] arr;
}

template <typename T>
T ListArray<T>::operator[](int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Index out of range");
    }
    return arr[pos];
}

template <typename T>
void ListArray<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) {
        throw std::out_of_range("Index out of range");
    }
    if (n == max) {
        resize(max * 2);
    }
    for (int i = n; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = e;
    ++n;
}

template <typename T>
void ListArray<T>::append(T e) {
    insert(n, e);
}

template <typename T>
void ListArray<T>::prepend(T e) {
    insert(0, e);
}

template <typename T>
T ListArray<T>::remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Index out of range");
    }
    T element = arr[pos];
    for (int i = pos; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --n;
    if (n > 0 && n == max / 4) {
        resize(max / 2);
    }
    return element;
}

template <typename T>
T ListArray<T>::get(int pos) const {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Index out of range");
    }
    return arr[pos];
}

template <typename T>
int ListArray<T>::search(T e) const {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == e) {
            return i;
        }
    }
    return -1;
}

template <typename T>
bool ListArray<T>::empty() const {
    return n == 0;
}

template <typename T>
int ListArray<T>::size() const {
    return n;
}

template <typename T>
void ListArray<T>::resize(int new_size) {
    T* new_arr = new T[new_size];
    for (int i = 0; i < n; ++i) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    max = new_size;
}

#endif

