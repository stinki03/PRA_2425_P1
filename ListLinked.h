#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <iostream>

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked();
    ~ListLinked();
    T operator[](int pos);

    // Declaración de la función friend como plantilla
    template <typename U>
    friend std::ostream& operator<<(std::ostream &out, const ListLinked<U> &list);

    void insert(int pos, T e) override;
    void append(T e) override;
    void prepend(T e) override;
    T remove(int pos) override;
    T get(int pos) override;
    int search(T e) override;
    bool empty() const override;
    int size() const override;
};

// Definición de la función friend fuera de la clase
template <typename T>
std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
    Node<T>* current = list.first;
    out << "[";
    while (current != nullptr) {
        out << *current;
        current = current->next;
        if (current != nullptr) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

// Implementación de los métodos de ListLinked
template <typename T>
ListLinked<T>::ListLinked() : first(nullptr), n(0) {}

template <typename T>
ListLinked<T>::~ListLinked() {
    Node<T>* current = first;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
T ListLinked<T>::operator[](int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* current = first;
    for (int i = 0; i < pos; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
void ListLinked<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* newNode = new Node<T>(e);
    if (pos == 0) {
        newNode->next = first;
        first = newNode;
    } else {
        Node<T>* current = first;
        for (int i = 0; i < pos - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    ++n;
}

template <typename T>
void ListLinked<T>::append(T e) {
    insert(n, e);
}

template <typename T>
void ListLinked<T>::prepend(T e) {
    insert(0, e);
}

template <typename T>
T ListLinked<T>::remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* current = first;
    if (pos == 0) {
        first = current->next;
    } else {
        for (int i = 0; i < pos - 1; ++i) {
            current = current->next;
        }
        Node<T>* temp = current->next;
        current->next = temp->next;
        current = temp;
    }
    T element = current->data;
    delete current;
    --n;
    return element;
}

template <typename T>
T ListLinked<T>::get(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* current = first;
    for (int i = 0; i < pos; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
int ListLinked<T>::search(T e) {
    Node<T>* current = first;
    int index = 0;
    while (current != nullptr) {
        if (current->data == e) {
            return index;
        }
        current = current->next;
        ++index;
    }
    return -1;
}

template <typename T>
bool ListLinked<T>::empty() const {
    return n == 0;
}

template <typename T>
int ListLinked<T>::size() const {
    return n;
}

#endif

