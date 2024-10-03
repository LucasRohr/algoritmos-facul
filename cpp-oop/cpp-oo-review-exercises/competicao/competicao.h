#include <iostream>
#include "../data/data.h"

#ifndef COMPETICAO_H
#define COMPETICAO_H

class Competicao {
    private:
        string nome;
        Data data;

    public:
        Competicao() = default;
        Competicao(string def_nome, Data def_data);

        void set_nome(string new_nome);
        string get_nome();

        void set_data(Data new_data);
        Data get_data();

        void imprime_data();
};

#endif
