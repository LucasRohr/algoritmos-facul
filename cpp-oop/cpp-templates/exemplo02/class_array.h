#include <iostream>

using namespace std;

// Define uma classe que recebe um tipo T generico, sendo ele o tipo do array que a classe representa
// A classe possui um ponteiro de T para percorrer o array em um tamanho do array

template <typename T>
class MyArray {
    private:
        T* p;
        int size;
    public:
        MyArray(T array[], int s);
        void print();
        T* bubble_sort();
};

// Implementa o construtor de MyArray, recebendo o tipo T e inicializando:
// - o ponteiro do array usando o tipo T com o tamanho s passado
// - o tamanho s
// - preenche o array usando o ponteiro p

template <typename T>
MyArray<T>::MyArray(T array[], int s) {
    p = new T[s];
    size = s;
    for(int i = 0; i < size; i++) {
        p[i] = array[i];
    }
}

// percorre o array usando aritmetica de ponteiro com ponteiro p
template <typename T>
void MyArray<T>::print() {
    for(int i = 0; i < size; i++) {
        cout << " " << *(p + i);
    }
    cout << endl;
}

template <typename T>
T* MyArray<T>::bubble_sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (p[j] > p[j + 1]) {
                swap(p[j], p[j + 1]);
            }
        }
    }

    return p;
}
