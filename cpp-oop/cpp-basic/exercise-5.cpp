#include <iostream>

using namespace std;

#define SIZE 20

int main()
{
    int matrix[SIZE][SIZE];
    int value, search_line = -1, search_column = -1;

    cout << "Digite o valor:" << endl;
    cin >> value;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << "Digite o elemento [" << i << "] [" << j << "] da matriz:" << endl;
            cin >> matrix[i][j];

            if (matrix[i][j] == value && search_line == -1 && search_column == -1)
            {
                search_line = i;
                search_column = j;
            }
        }
    }

    if (search_line == -1 && search_column == -1)
    {
        cout << "Valor não encontrado" << endl;
        return 1;
    }

    cout << "Valor " << value << " encontrado na posicao [" << search_line << "][" << search_column << "]" << endl;

    return 0;
}