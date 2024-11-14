/**
 * Implementação de uma pilha com armazenamento estático 
 * usando vetor (array unidimensional).
 */

#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <iostream>
#include "stack.h"

using namespace std;

template <typename T>
class StaticStack: public Stack<T> {
    protected:
        // Índice do elemento no topo da pilha
        int top;

        // Array que armazena as referências para os elementos
        T* elements;
    public:
        /**
         * Constrói uma pilha com um tamanho máximo.
         */
        StaticStack(int max_size);
        
        bool isEmpty();
        bool isFull();
        int numElements();
        int push(T element);
        int pop(T& result);
        int return_top(T& result);
        bool contains(T element);
        void print();
};

template <typename T>
StaticStack<T>::StaticStack(int max_size) {
    elements = new T[max_size];
    top = -1;
}

template <typename T>
bool StaticStack<T>::isEmpty() {
    return top == -1;
}

template <typename T>
bool StaticStack<T>::isFull() {
    return top == ((sizeof(elements) / sizeof(elements[0])) - 1);
}

template <typename T>
int StaticStack<T>::numElements() {
    return top + 1;
}

/**
 * Retorna 0 se o elemento foi inserido na pilha.
 * Retorna 2 se a pilha estiver cheia.
 */
template <typename T>
int StaticStack<T>::push(T element) {
    if(isFull())
        return 2;
    else {
        elements[++top] = element;
        return 0;
    }
}

/**
 * Retorna 0 se o elemento foi inserido na pilha.
 * Retorna 3 se a pilha estiver vazia.
 */
template <typename T>
int StaticStack<T>::pop(T& result) {
    if(isEmpty())
        return 3;
    else {
        result = elements[top];
        top--;

        return 0;
    }
}

/**
 * Retorna 0 se o elemento foi inserido na pilha.
 * Retorna 3 se a pilha estiver vazia.
 */
template <typename T>
int StaticStack<T>::return_top(T& result) {
    if(isEmpty())
        return 3;
    else {
        result = elements[top];

        return 0;
    }
}

template <typename T>
bool StaticStack<T>::contains(T element) {
    bool has_element = false;
    T curr_element;
    int i = 0, j = 0;
    StaticList<T> list(numElements());

     while(isEmpty() == false && has_element == false) {
        pop(curr_element);
        list.insert(curr_element, i);
        i++;

        if (curr_element == element) {
            has_element = true;
        }
    }

    while(j < i) {
        push(curr_element);
        j++;
    }

    return has_element;
}

template <typename T>
void StaticStack<T>::print() {
    for(int i = 0; i < top; i++) {
        cout << " " << *(elements + i);
    }
    
    cout << endl;
}

#endif