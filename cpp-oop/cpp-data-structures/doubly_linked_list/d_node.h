/**
 * Authors:
 * Pietro do Couto Freitas
 * Lucas Rohr Carreño
 */

#ifndef D_NODE
#define D_NODE

#include <iostream>

using namespace std;

template <typename T>
class DNode {
    protected:
        // The element stored by this node
        T element;

        // A pointer for the previous element
        DNode<T>* previous;

        // A pointer for the next element
        DNode<T>* next;
    public:
        DNode(T element);
        T getElement() const;
        void setElement(T element);
        DNode<T>* getPrevious() const;
        void setPrevious(DNode<T>* previous);
        void setNext(DNode<T>* next);
        DNode<T>* getNext() const;
};

/**
 * Default DNode constructor
 * previous is started as nullptr
 * next is started as nullptr
 * @param element The element to be stored by the node
 */
template <typename T>
DNode<T>::DNode(T element) {
    this->element = element;
    this->previous = nullptr;
    this->next = nullptr;
}

/**
 * Gets the element stored by the node
 * @returns The element stored by the node
 */
template <typename T>
T DNode<T>::getElement() const {
    return this->element;
}

/**
 * Sets the element stored by the node
 * @param element element to be stored by the node
 */
template <typename T>
void DNode<T>::setElement(T element) {
    this->element = element;
}

/**
 * Gets the previous node pointer
 * @returns a pointer for the next node or nullptr if non-existent
 */
template <typename T>
DNode<T>* DNode<T>::getPrevious() const {
    return this->previous;
}

/**
 * Sets the previous node pointer
 * @param pointer A pointer for the previous node
 */
template <typename T>
void DNode<T>::setPrevious(DNode<T>* previous) {
    this->previous = previous;
}

/**
 * Gets the next node pointer
 * @returns a pointer for the next node or nullptr if non-existent
 */
template <typename T>
DNode<T>* DNode<T>::getNext() const {
    return this->next;
}

/**
 * Sets the next node pointer
 * @param pointer A pointer for the next node
 */
template <typename T>
void DNode<T>::setNext(DNode<T>* next) {
    this->next = next;
}

#endif