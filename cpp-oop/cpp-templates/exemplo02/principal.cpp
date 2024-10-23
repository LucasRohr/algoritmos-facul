#include <iostream>
#include "class_array.h"

#define SIZE 4

using namespace std;

int main() {
    int array[SIZE] = {4, 3, 1, 2};
    MyArray<int> a(array, SIZE);
    int* sorted_array;

    a.print(); // printa " 4 3 1 2"

    sorted_array = a.bubble_sort();

    // printa " 1 2 3 4"
    for(int i = 0; i < SIZE; i++) {
        cout << " " << *(sorted_array + i);
    }

    cout << endl;

    return 0;
}
