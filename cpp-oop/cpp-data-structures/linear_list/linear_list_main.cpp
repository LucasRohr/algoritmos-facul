#include "linear_list.h"

#define SIZE 8

int main() {
    int array[SIZE];
    LinearList<int> list(array, SIZE);

    cout << "list vazia? " << list.is_empty() << endl << endl;
    cout << "list cheia? " << list.is_full() << endl << endl;

    list.add_position(5, 0);
    list.add_position(-4, 1);
    list.add_position(8, 2);
    list.add_position(0, 3);
    list.add_position(-1, 4);
    list.add_position(6, 5);
    list.add_position(2, 6);

    cout << "total de elementos = " << list.count_elements() << endl;
    list.print();
    cout << endl;

    list.remove_position(2); // remove 8 from the list
    list.print();
    cout << endl;

    list.remove_position(0); // remove 5 from the list
    list.print();
    cout << endl;
    cout << "total de elementos = " << list.count_elements() << endl << endl;

    cout << "elemento na posicao 3 = " << list.find_element(3) << endl << endl;
    cout << "posicao do elemento -1 = " << list.find_position(-1) << endl << endl;

    list.add_position(1, 5);
    list.add_position(2, 6);
    list.add_position(3, 7);

    list.print();
    cout << endl;

    list.add_position(3, 7);

    cout << "list cheia? " << list.is_full() << endl << endl;

    return 0;
}
