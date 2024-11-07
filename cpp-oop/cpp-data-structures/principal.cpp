/**
 * Código exemplo para uso das estruturas:
 * StaticList, StaticQueue e StaticStack
 */

#include <iostream>
#include "staticList.h"
#include "staticQueue.h"
#include "staticStack.h"

using namespace std;

template <typename T>
void invert_stack(StaticStack<T>& stack) {
    StaticStack<T> aux_stack(stack.numElements());
    T popped;
    int i = 0;

    while (i < stack.numElements()) {
        stack.pop(popped);
        aux_stack.push(popped);
        i++;
    }

    stack = aux_stack;
}

template <typename T>
bool stack_contains(StaticStack<T> stack, T element, int& position) {
    StaticStack<T> aux_stack(stack.numElements());
    T popped;
    int i = 0;

    // Enquanto nao achou e nao chegou no fim da stack, transfere para aux
    while (element != popped && i < stack.numElements()) {
        stack.pop(popped);
        aux_stack.push(popped);
        i++;
    }

    // se chegou com i no final, nao achou
    if (i == stack.numElements()) {
        return false;
    }

    // caso contrario, atribui position
    position = stack.numElements() - i;

    // transfere de volta pra stack original
    while (i >= 0) {
        aux_stack.pop(popped);
        stack.push(popped);
    }

    return true;
}

int main() {
    int default_code = -1; // Define um código de retorno default para a chamada
                           // das funções
    int& result = default_code; // Inicializa uma veriável de referência com o 
                                // código padrão
    
    StaticList<int> sl(5);  // Cria uma lista estática de tipo int com 5 posições
    StaticQueue<int> sq(5); // Cria uma fila estátia de tipo int com 5 posições
    StaticStack<int> ss(5); // Cria uma pilha estática de tipo int com 5 posições

    int removed_element;

    /**
     * Tenta inserir o elemento 5 na posição 0 (zero) da lista.
     * Verifica se o elemento foi inserido por meio do código de retorno 
     * da função.
     */
    if(sl.insert(5, 0) == 0)
        cout << "Elemento inserido com sucesso na lista!" << endl;
    cout << "\n";

    sl.insert(5, 1);
    sl.insert(6, 2);

    sl.print();
    sl.depup();
    //sl.remove_interval(0, 1);
    sl.print();

    /**
     * Tenta remover um elemento da fila vazia.
     * Verifica o código de retorno da função.
     */
    int code = sq.dequeue(result);
    if(code)
        cout << "Fila vazia!!" << endl;
    cout << "\n";

    sq.enqueue(1);
    sq.enqueue(2);
    sq.enqueue(3);

    sq.print();

    cout << "contem 2 = " << sq.contains(2) << endl;

    sq.flip();
    sq.enqueueWithPriority(4);

    sq.print();

    /**
     * Tenta inserir o elemento 4 na pilha.
     * Verifica se o elemento foi inserido por meio do código de retorno
     * da função.
     */
    if(ss.push(4) == 0)
        cout << "Elemento inserido com sucesso na pilha!" << endl;
    cout << "\n";

    ss.push(1);
    ss.push(2);

    cout << "contem 4 = " << ss.contains(4) << endl;

    invert_stack(ss);

    ss.print();

    return 0;
}
