/**
 * Authors:
 * Pietro do Couto Freitas
 * Lucas Rohr Carreño
 */

/**
 * Implementação de uma lista linear com armazenamento dinâmico, baseado em nós
 * com encadeamento em duplo sentido (duplamente encadeada).
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include "list.h"
#include "d_node.h"

using namespace std;

template <typename T>
class DoublyLinkedList : public List<T> {
protected:
    DNode<T> *head;
    DNode<T> *tail;
    int num_elements;

public:
    DoublyLinkedList();
    int numElements();
    bool isEmpty();
    bool isFull();
    void insertFirst(T element);
    void insertLast(T element);
    int insert(T element, int pos);
    int removeFirst(T &result);
    int removeLast(T &result);
    int remove(int pos, T &result);
    int get(int pos, T &result);
    int search(const T &element);
    void print();
};

/**
 * Constrói uma lista inicialmente vazia.
 */
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    num_elements = 0;
}

template <typename T>
int DoublyLinkedList<T>::numElements() {
    return num_elements;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() {
    return num_elements == 0;
}

template <typename T>
bool DoublyLinkedList<T>::isFull() {
    // Uma lista com alocação dinâmica nunca está cheia.
    return false;
}

/**
 * Insere um novo elemento na posição inicial da lista.
 */
template <typename T>
void DoublyLinkedList<T>::insertFirst(T element) {
    // Cria um novo nó e o torna o novo "head"
    DNode<T> *new_node = new DNode<T>(element);

    // Se lista vazia, apenas atribui novo nodo como head e tail
    if (isEmpty()) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->setNext(head); // Próximo do novo nodo é o primeiro atual
        new_node->setPrevious(nullptr); // Anterior do novo nodo é nulo
        head->setPrevious(new_node); // Anterior do primeiro nodo atual é o novo nodo
        head = new_node; // Atualiza head como o novo nodo
    }

    // Ajusta o total de elementos
    num_elements++;
}

/**
 * Insere um novo elemento no final da lista.
 */
template <typename T>
void DoublyLinkedList<T>::insertLast(T element) {
    // Cria um novo nó e o torna o "tail"
    DNode<T> *new_node = new DNode<T>(element);

    // Se lista vazia, apenas atribui novo nodo como head e tail
    if (isEmpty()) {
        head = new_node;
        tail = new_node;
    } else {
        tail->setNext(new_node); // Próximo do último nodo atual é o novo nodo
        new_node->setPrevious(tail); // Anterior do novo nodo é o último atual
        new_node->setNext(nullptr); // Próximo do novo é nulo
        tail = new_node; // Atualiza tail como o novo nodo
    }

    // Ajusta o total de elementos
    num_elements++;
}

/**
 * Retorna 1 se a posição informada não está correta.
 */
template <typename T>
int DoublyLinkedList<T>::insert(T element, int pos) {
    // Verifica se a posição lida é válida
    if (pos < 0 || pos > num_elements)
        return 1;

    // Casos especiais: inserção no início
    if (pos == 0) {
        insertFirst(element);
    } else {
        // Inserção no final
        if (pos == num_elements) {
            insertLast(element);
        } else { // Inserção no meio da lista
            // Localiza o nó imediatamente anterior à posição onde o novo nó será inserido
            DNode<T> *prev = head;

            for (int i = 0; i < pos - 1; i++)
                prev = prev->getNext();

            // Cria um novo nó e o posiciona logo após "prev", ajustando os apontamentos e o total de elementos
            DNode<T> *new_node = new DNode<T>(element);

            new_node->setNext(prev->getNext()); // Próximo do novo nodo é o próximo atual do nodo anterior
            new_node->setPrevious(prev); // Anterior ao novo nodo é o anterior encontrado na busca (laço for)
            prev->getNext()->setPrevious(new_node); // O anterior do próximo atual ao nodo prev é o nodo nodo criado
            prev->setNext(new_node); // Por fim, atualiza o próximo do nodo prev como o nodo novo criado
            num_elements++; // Atualiza o total de elementos
        }
    }

    return 0;
}

/**
 * Remove o primeiro elemento da lista.
 * Retorna 0 se o elemento existir na lista.
 * Retorna 3 se a lista estiver vazia.
 */
template <typename T>
int DoublyLinkedList<T>::removeFirst(T &result)
{
    if (isEmpty())
        return 3;

    // Guarda a referência do elemento sendo removido
    result = head->getElement();

    // Se a lista possui um único elemento: head e tail = nullptr
    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        // Senão, o segundo elemento será o head
        head = head->getNext();
    }

    // Ajusta o total de elementos e retorna o removido
    num_elements--;
    return 0;
}

/**
 * Remove o último elemento da lista.
 * Retorna 0 se o elemento existir na lista.
 * Retorna 3 se a lista estiver vazia.
 */
template <typename T>
int DoublyLinkedList<T>::removeLast(T &result)
{
    if (isEmpty())
        return 3;

    // Guarda uma referência do elemento sendo removido
    result = tail->getElement();

    // Se a lista possui um único elemento: head e tail = nullptr
    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        // Senão, necessário percorrer o encadeamento até chegar ao nó
        // imediatamente anterior ao último
        DNode<T> *prev = head;
        while (prev->getNext() != tail)
            prev = prev->getNext();

        // Atualiza tail
        tail = prev;
        prev->setNext(nullptr);
    }

    // Ajusta o total de elementos e retorna o removido
    num_elements--;
    return 0;
}

/**
 * Remove um elemento de uma posição específica da lista.
 * Retorna 0 indicando a remoção do elemento da lista.
 * Retorna 1 se a posição informada não estiver correta.
 */
template <typename T>
int DoublyLinkedList<T>::remove(int pos, T &result)
{
    if (pos < 0 || pos >= num_elements)
        return 1;

    if (pos == 0)
        removeFirst(result);
    else
    {
        if (pos == num_elements - 1)
            removeLast(result);
        else
        { // Remoção do meio da lista
            // Localiza o nós imediatamente anterior à posição de onde o
            // elemento será removido
            DNode<T> *prev = head;
            for (int i = 0; i < pos - 1; i++)
                prev = prev->getNext();

            // Guarda uma referência do elemento que será removido
            result = prev->getNext()->getElement();

            // Ajusta o encadeamento "pulando" o nó removido
            prev->setNext(prev->getNext()->getNext());

            // Ajusta o total de elementos e retorna o elemento removido
            num_elements--;
        }
    }

    return 0;
}

/**
 * Busca um elemento de uma posição específica da lista.
 * Retorna 0 indicando a obtenção do elemento da lista.
 * Retorna 1 se a posição informada não estiver correta.
 */
template <typename T>
int DoublyLinkedList<T>::get(int pos, T &result) {
    if (pos < 0 || pos >= num_elements)
        return 1;

    DNode<T> *current = head;
    for (int i = 0; i < pos; i++)
        current = current->getNext();

    result = current->getElement();

    return 0;
}

template <typename T>
int DoublyLinkedList<T>::search(const T &element) {
    // Percorre o encadeamento até encontrar o elemento
    DNode<T> *current = head;

    int i = 0;
    while (current != nullptr) {
        if (element == current->getElement())
            return i;
        i++;
        current = current->getNext();
    }

    // Se chegar até aqui, o elemento não foi encontrado
    return -1;
}

template <typename T>
void DoublyLinkedList<T>::print() {
    DNode<T> *node = head;

    for (int i = 0; i < num_elements; i++) {
        cout << node->getElement() << " ";
        node = node->getNext();
    }

    cout << endl;
}

#endif
