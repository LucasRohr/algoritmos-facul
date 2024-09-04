#include <iostream>

using namespace std;

#define SIZE 3

int main()
{
    int matrix[SIZE][SIZE];
    int min_value = 2147483647;
    int min_value_line;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << "Digite o elemento [" << i << "] [" << j << "] da matriz:" << endl;
            cin >> matrix[i][j];

            if (matrix[i][j] < min_value)
            {
                min_value = matrix[i][j];
                min_value_line = i;
            }
        }
    }

    cout << "Linha contendo o menor valor: " << min_value_line << endl;

    return 0;
}