#include <iomanip>
#include "./atleta.h"

Atleta::Atleta(string def_nome, int def_idade) {
    nome = def_nome;
    idade = def_idade;
}

void Atleta::set_nome(string new_nome) {
    nome = new_nome;
}

string Atleta::get_nome() {
    return nome;
}

void Atleta::set_idade(int new_idade) {
    idade = new_idade;
}

int Atleta::get_idade() {
    return idade;
}

void Atleta::imprime_info() {
    cout << "Dados do atleta: " << endl
        << "Nome: " << std::setw(6) << nome << endl
        << "Idade: " << std::setw(7) << idade << endl;
}
