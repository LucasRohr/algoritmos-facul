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
    int& result = default_code; // Inicializa uma variável de referência com o código padrão

    DoublyLinkedList<int> dll;  // Cria uma lista duplamente encadeada de tipo int

    // Verifica lista vazia antes das inserções
    cout << "Lista está vazia? - " << (dll.isEmpty() ? "Sim" : "Não") << endl << endl;

    // Insere os elementos 5, 6, 7 e 8 em sequência na lista
    dll.insert(5, 0);
    dll.insert(6, 1);
    dll.insert(7, 2);
    dll.insert(8, 3);

    // Insere o elemento 9 no início da lista
    dll.insertFirst(9);
    
    // Insere o elemento 10 no fim da lista
    dll.insertLast(10);

    // Imprime os elementos da lista
    dll.print();

    cout << endl << endl;

    // Verifica total de elementos da lista
    cout << "Total de elementos da lista: " << dll.numElements() << endl;

    // Verifica lista vazia depois das inserções
    cout << "Lista está vazia? - " << (dll.isEmpty() ? "Sim" : "Não") << endl;

    // Verifica lista cheia
    cout << "Lista está cheia? - " << (dll.isFull() ? "Sim" : "Não") << endl << endl;

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

    cout << "Elemento removido da posição 1: " << removed << endl << endl;

    // Imprime os elementos da lista
    dll.print();

    cout << endl << endl;

    // Verifica total de elementos da lista
    cout << "Total de elementos da lista após remoção: " << dll.numElements() << endl;

    if(dll.get(2, result) == 0) {
        cout << "Elemento na posição 2: " << result << " " << endl; 
    }

    result = dll.search(7);

    if(result != -1) {
        cout << "Posição do elemento 7: " << result << " " << endl; 
    }

    return 0;
}
