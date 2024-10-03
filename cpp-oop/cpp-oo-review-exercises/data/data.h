#include <iostream>

#ifndef DATA_H
#define DATA_H

using namespace std;

class Data {
    private:
        int dia;
        int mes;
        int ano;

    public:
        Data() = default;
        Data(int def_dia, int def_mes, int def_ano);

        void set_dia(int new_dia);
        int get_dia();

        void set_mes(int new_mes);
        int get_mes();

        void set_ano(int new_ano);
        int get_ano();

        void imprime_data();
};

#endif
