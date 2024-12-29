#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data, Node<T>* next = nullptr);

    // Declaración de la función friend como plantilla
    template <typename U>
    friend std::ostream& operator<<(std::ostream &out, const Node<U> &node);
};

// Definición de la función friend fuera de la clase
template <typename T>
std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
    out << node.data;
    return out;
}

#endif

