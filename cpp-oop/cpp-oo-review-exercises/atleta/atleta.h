#include <iostream>

#ifndef ATLETA_H
#define ATLETA_H

using namespace std;

class Atleta {
    private:
        string nome;
        int idade;

    public:
        Atleta() = default;
        Atleta(string def_nome, int def_idade);

        virtual void set_nome(string new_nome);
        virtual string get_nome();

        virtual void set_idade(int new_idade);
        virtual int get_idade();

        virtual void imprime_info();
};

#endif
