/**
 * Authors:
 * Pietro do Couto Freitas
 * Lucas Rohr Carreño
 */

#include <iostream>
#include "doubly_linked_list.h"

using namespace std;

int main() {
    int default_code = -1; // Define um código de retorno default para a chamada  das funções

    int& result = default_code; // Inicializa uma veriável de referência com o  código padrão

    DoublyLinkedList<int> dll;  // Cria uma lista duplamente encadeada de tipo int

    /**
     * Insere os elementos 5, 6, 7 e 8 em sequência na lista.
     */
    dll.insert(5, 0);
    dll.insert(6, 1);
    dll.insert(7, 2);
    dll.insert(8, 3);

    /**
     * Insere o elemento 9 no início da lista.
     */
    dll.insertFirst(9);
    
    /**
     * Insere o elemento 10 no início da lista.
     */
    dll.insertLast(10);

    /**
     * Imprime os elementos da lista.
     */
    cout << "==== ELEMENTOS NA LISTA ====" << endl;
    int num_elements = dll.numElements();
    for(int i = 0; i < num_elements; i++) {
        if(dll.get(i, result) == 0)
            cout << result << " "; 
    }

    cout << endl;

    int removedFirst;
    int removedLast;
    int removed;

    /**
     * Remove o elemento no início da lista.
     */
    dll.removeFirst(removedFirst);

    cout << "Elemento removido do inicio: " << removedFirst << endl;

    /**
     * Remove o elemento no fim da lista.
     */
    dll.removeLast(removedLast);

    cout << "Elemento removido do fim: " << removedLast << endl;

    /**
     * Remove o elemento na posição 1.
     */
    dll.remove(1, removed);

    cout << "Elemento removido da posição 1: " << removed << endl;

    /**
     * Imprime os elementos da lista.
     */
    cout << "==== ELEMENTOS NA LISTA ====" << endl;
    num_elements = dll.numElements();
    for(int i = 0; i < num_elements; i++) {
        if(dll.get(i, result) == 0)
            cout << result << " "; 
    }

    cout << endl;

    return 0;
}
