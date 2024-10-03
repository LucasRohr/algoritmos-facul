#include <iostream>
#include "../atleta/atleta.h"

#ifndef NADADOR_H
#define NADADOR_H

class Nadador: public Atleta {
    private:
        string categoria;

    public:
        Nadador() = default;
        Nadador(string def_nome, int def_idade, string def_categoria);

        void set_categoria(string new_categoria);
        string get_categoria();

        void imprime_info();
};

#endif
