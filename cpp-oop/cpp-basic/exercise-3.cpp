#include <iostream>

using namespace std;

#define SIZE 3

void print_matrix(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

void sum_lines(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        matrix[1][i] = matrix[0][i] + matrix[1][i];
    }
}

void mult_lines(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        matrix[1][i] = matrix[0][i] * matrix[1][i];
    }
}

int main()
{
    int matrix[SIZE][SIZE];

    if (SIZE < 2)
    {
        cout << "Matriz tem menos de duas linhas, encerrando..." << endl;
        return 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << "Digite o elemento [" << i << "] [" << j << "] da matriz:" << endl;
            cin >> matrix[i][j];
        }
    }

    // Sum elements from L1 and L2, saves in L2
    sum_lines(matrix);

    cout << "Matriz resultante da soma:" << endl;
    print_matrix(matrix);

    // ======= Reset matrix ==========

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << "Digite o elemento [" << i << "] [" << j << "] da matriz:" << endl;
            cin >> matrix[i][j];
        }
    }

    // Multiplies elements from L1 and L2, saves in L2
    mult_lines(matrix);

    cout << "Matriz resultante do produto:" << endl;
    print_matrix(matrix);

    return 0;
}