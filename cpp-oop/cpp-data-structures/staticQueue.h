/**
 * Implementação de uma fila com armazenamento estático 
 * usando vetor (array unidimensional).
 */

#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <iostream>
#include "queue.h"

using namespace std;

template <typename T>
class StaticQueue: public Queue<T> {
    protected:
        // Índice para o primeiro elemento
        int first;

        // Índice para o segundo elemento
        int last;

        // Array que armazena as referências para os elementos
        T* elements;
    public:
        /**
         * Constrói uma fila com tamanho máximo
         */
        StaticQueue(int max_size);

        bool isEmpty();
        bool isFull();
        int numElements();
        int enqueue(T element);
        int dequeue(T& result);
        int front(T& result);
        int back(T& result);
        bool contains(T element);
        void flip();
        void enqueueWithPriority(T element);
        void print();
};

template <typename T>
StaticQueue<T>::StaticQueue(int max_size) {
    elements = new T[max_size];
    first = -1;
    last = -1;
}

template <typename T>
bool StaticQueue<T>::isEmpty() {
    return first == -1;
}

template <typename T>
bool StaticQueue<T>::isFull() {
    return last == ((last + 1) % (sizeof(elements) / sizeof(elements[0])));
}

template <typename T>
int StaticQueue<T>::numElements() {
    if(isEmpty())
        return 0;
    else {
        int n = sizeof(elements) / sizeof(elements[0]);
        return ((n + last + first) % n) + 1;
    }
}

/** 
* Retorna 0 se o elemento foi inserido da fila.
* Retorna 2 se a fila estiver cheia.
*/
template <typename T>
int StaticQueue<T>::enqueue(T element) {
    if(isFull())
        return 2;
    else {
        if(last == -1) {
            first = 0;
            last = 0;
        }
        else
            last = (last + 1) % (sizeof(elements) / sizeof(elements[0]));
        elements[last] = element;

        return 0;
    }
}

/** 
* Retorna 0 se o elemento foi removido da fila.
* Retorna 3 se a fila estiver vazia.
*/
template <typename T>
int StaticQueue<T>::dequeue(T& result) {
    if(isEmpty())
        return 3;
    else {
        result = elements[first];
        if(first == last) {
            first = -1;
            last = -1;
        }
        else {
            first = (first + 1) % (sizeof(elements) / sizeof(elements[0]));
        }
        
        return 0;
    }
}

/** 
* Retorna 0 se a lista não estiver vazia.
* Retorna 3 se a fila estiver vazia.
*/
template <typename T>
int StaticQueue<T>::front(T& result) {
    if(isEmpty())
        return 3;
    else {
        result = elements[first];
        return 0;
    }
}

/** 
* Retorna 0 se a lista não estiver vazia.
* Retorna 3 se a fila estiver vazia.
*/
template <typename T>
int StaticQueue<T>::back(T& result) {
    if(isEmpty())
        return 3;
    else {
        result = elements[last];
        return 0;
    }
}

template <typename T>
bool StaticQueue<T>::contains(T element) {
    bool has_element = false;
    T curr_element;
    int i = 0, j = 0;
    StaticList<T> list(numElements());

    while(isEmpty() == false && has_element == false) {
        dequeue(curr_element);
        list.insert(curr_element, i);
        i++;

        if (curr_element == element) {
            has_element = true;
        }
    }

    while(j < i) {
        enqueue(curr_element);
        j++;
    }

    return has_element;
}

template <typename T>
void StaticQueue<T>::flip() {
    T curr_element;
    int i = 0;
    StaticList<T> list(numElements());

    while(isEmpty() == false) {
        dequeue(curr_element);
        list.insert(curr_element, i);
        i++;
    }

    while(i >= 0) {
        enqueue(curr_element);
        i--;
    }
}

template <typename T>
void StaticQueue<T>::enqueueWithPriority(T element) {
    if(isFull() == false) {
        if(last == -1) {
            first = 0;
            last = 0;
        } else {
            last = (last + 1) % (sizeof(elements) / sizeof(elements[0]));
        }

        elements[first] = element;
    }
}

template <typename T>
void StaticQueue<T>::print() {
    for(int i = first; i < last; i++) {
        cout << " " << *(elements + i);
    }
    
    cout << endl;
}

#endif
