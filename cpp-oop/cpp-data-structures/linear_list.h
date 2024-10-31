#include <iostream>

using namespace std;

template <typename T>
class LinearList {
    private:
        T* pointer;
        int size;
        int num_elements;

    public:
        LinearList(T* pointer, int size);

        int count_elements();
        bool is_empty();
        bool is_full();

        void add_position(T element, int position);
        T remove_position(int position);
        T find_element(int position);
        int find_position(T element);

        void print();
};

template <typename T>
LinearList<T>::LinearList(T* list, int size) {
    this->pointer = new T[size];
    this->size = size;
    this->num_elements = 0;
}

template <typename T>
void LinearList<T>::print() {
    for(int i = 0; i < size; i++) {
        cout << " " << *(pointer + i);
    }
    
    cout << endl;
}

template <typename T>
int LinearList<T>::count_elements() {
    return this->num_elements;
}

template <typename T>
bool LinearList<T>::is_empty() {
    return this->num_elements == 0;
}

template <typename T>
bool LinearList<T>::is_full() {
    return this->num_elements == this->size;
}

template <typename T>
void LinearList<T>::add_position(T element, int position) {
    if(this->num_elements < this->size) {
        for (int i = position; i < (size - 1); i++) {
            pointer[i + 1] = pointer[i];
        }

        this->num_elements++;

        pointer[position] = element;
    } else {
        cout << "Lista cheia, nao eh possivel inserir elementos" << endl;
    }
}

template <typename T>
T LinearList<T>::remove_position(int position) {
    if (position < this->num_elements) {
        T element = pointer[position];

        for (int i = position; i < (size - 1); i++) {
            pointer[i] = pointer[i+1];
        }

        this->num_elements--;

        return element;
    } else {
        cout << "Posicao invalida, retornando primeiro elemento..." << endl;
        return pointer[0];
    }
}

template <typename T>
T LinearList<T>::find_element(int position) {
    return pointer[position];
}

template <typename T>
int LinearList<T>::find_position(T element) {
    int position = -1;

    for (int i = 0; i < size; i++) {
        if (pointer[i] == element) {
            position = i;
        }
    }

    return position;
}
