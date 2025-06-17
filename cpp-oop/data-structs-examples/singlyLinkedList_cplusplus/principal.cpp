/**
 * Código exemplo para uso da estrutura:
 * SinglyLinkedList
 */

#include <iostream>
#include <iomanip>
#include "singlyLinkedList.h"

using namespace std;

int convertToInt(SinglyLinkedList<int> sll) {
    int number = 0;
    int square = sll.numElements() - 1;
    Node<int>* element = sll.head;

    for(int i = 0; i < sll.numElements(); i++) {
        number += element->getElement() * pow(10, square);
        element = element->getNext();
        square--;
    }

    return number;
}

int sumAllSingleLinkedList(SinglyLinkedList<int> sll) {
    Node<int>* element = sll.head;
    int sum = 0;

    for(int i = 0; i < sll.numElements(); i++) {
        sum += element->getElement();
        element = element->getNext();
    }

    return sum;
}

void print_sll(SinglyLinkedList<int> sll) {
    /**
     * Imprime os elementos da lista.
     */
    cout << "==== ELEMENTOS NA LISTA ====" << endl;
    int result;
    int num_elements = sll.numElements();
    for(int i = 0; i < num_elements; i++) {
        if(sll.get(i, result) == 0)
            cout << result << " "; 
    }
    cout << "\n";
}

int main() {
    SinglyLinkedList<int> sll;  // Cria uma lista encadeada de tipo int
    SinglyLinkedList<int> sll_split;

    /**
     * Insere os elementos 5, 6, 7 e 8 em sequência na lista.
     */
    sll.insert(4, 0);
    sll.insert(1, 1);
    sll.insert(0, 2);
    sll.insert(1, 3);

    /**
     * Insere o elemento 9 no início da lista.
     */
    sll.insertFirst(9);
    
    /**
     * Insere o elemento 10 no início da lista.
     */
    sll.insertLast(10);

    print_sll(sll);

    cout << "convertToInt(sll) = " << convertToInt(sll) << endl;
    cout << "sumAllSingleLinkedList(sll) = " << sumAllSingleLinkedList(sll) << endl;

    sll.split(0, sll_split);

    print_sll(sll);
    print_sll(sll_split);

    return 0;
}
