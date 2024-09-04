#include <iostream>

using namespace std;

#define SIZE 6

int main()
{
    int matrix[SIZE][SIZE];
    int arrayV[SIZE * SIZE];
    int valueA;
    int array_index = 0;

    cout << "Digite o valor A:" << endl;
    cin >> valueA;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << "Digite o elemento [" << i << "] [" << j << "] da matriz:" << endl;
            cin >> matrix[i][j];

            arrayV[array_index] = matrix[i][j] * valueA;
            array_index++;
        }
    }

    cout << "Valores armazenados no array V:" << endl;

    for (int i = 0; i < (SIZE * SIZE); i++)
    {
        cout << arrayV[i] << " ";
    }

    cout << endl;

    return 0;
}