#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int max_value;
    int initial_index = 0;

    cout << "Digite o valor do numero maximo" << endl;
    cin >> max_value;

    if (max_value % 2 == 0)
    {
        cout << "Valor digitado eh par, encerrando programa..." << endl;
        return 1;
    }

    for (int i = 0; i < (max_value / 2) + 1; i++)
    {
        cout << std::setw((i + 1) * 2);

        for (int j = initial_index; j < (max_value - i); j++)
        {
            cout << (j + 1) << " ";
        }

        cout << endl;

        initial_index++;
    }

    return 0;
}