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
    T get(int pos) override;
    int search(T e) override;
    bool empty() override;
    int size() override;

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

#endif
