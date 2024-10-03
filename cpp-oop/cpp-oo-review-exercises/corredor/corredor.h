#include <iostream>
#include "../atleta/atleta.h"
#include "../competicao/competicao.h"

#ifndef CORREDOR_H
#define CORREDOR_H

class Corredor: public Atleta {
    private:
        double peso;
        Competicao competicao;

    public:
        Corredor() = default;
        Corredor(string def_nome, int def_idade, double def_peso, Competicao def_competicao);

        void set_peso(double new_peso);
        double get_peso();

        void set_competicao(Competicao new_competicao);
        Competicao get_competicao();

        void imprime_competicao();
        void imprime_info();
};

#endif
