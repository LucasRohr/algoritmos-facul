#ifndef D_NODE_H
#define D_NODE_H

#include <iostream>

using namespace std;

template <typename T>
class DNode
{
protected:
    T element;
    DNode<T> *next;

public:
    DNode(T element);

    T getElement() const;
    void setElement(T element);

    DNode<T> *getNext() const;
    void setNext(DNode<T> *next);
};

template <typename T>
DNode<T>::DNode(T element)
{
    this->element = element;
    next = nullptr;
}

template <typename T>
T DNode<T>::getElement() const
{
    return element;
}

template <typename T>
void DNode<T>::setElement(T element)
{
    this->element = element;
}

template <typename T>
DNode<T> *DNode<T>::getNext() const
{
    return next;
}

template <typename T>
void DNode<T>::setNext(DNode<T> *next)
{
    this->next = next;
}

#endif
