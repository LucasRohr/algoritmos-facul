/**
 * Classe/interface que define o comportamento de uma lista linear.
 */

#ifndef LIST_H
#define LIST_H

using namespace std;

template <typename T>
class List {
    public:
        /**
         * Informa a quantidade de elementos armazenados na lista.
         */
        virtual int numElements() = 0;

        /**
         * Informa se a lista está vazia.
         */
        virtual bool isEmpty() = 0;

        /**
         * Informa se a lista está cheia.
         */
        virtual bool isFull() = 0;

        /**
         * Insere um novo elemento na posição indicada.
         */
        virtual int insert(T element, int pos) = 0;

        /**
         * Remove o elemento da posição indicada.
         */
        virtual int remove(int pos, T& result) = 0;

        /**
         * Retorna o elemento da posição indicada, sem removê-lo.
         */
        virtual int get(int pos, T&result) = 0;

        /**
         * Localiza na lista a primeira ocorrência do elemento indicado.
         */
        virtual int search(const T& element) = 0;

        // Retorna quantas ocorrencias do elemento tem na lista
        virtual int count_element(T& element) = 0;

        // Remove ocorrências múltiplas de elementos na lista
        virtual void depup() = 0;

        // Remove elementos em um intervalo na lista
        virtual int remove_interval(int begin, int end) = 0;

        virtual void print() = 0;
};

#endif
