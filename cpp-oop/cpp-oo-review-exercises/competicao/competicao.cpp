#include <iomanip>
#include "competicao.h"

Competicao::Competicao(string def_nome, Data def_data) {
    nome = def_nome;
    data = def_data;
}

void Competicao::set_nome(string new_nome) {
    nome = new_nome;
}

string Competicao::get_nome() {
    return nome;
}

void Competicao::set_data(Data new_data) {
    data = new_data;
}

Data Competicao::get_data() {
    return data;
}

void Competicao::imprime_data() {
    cout << "Data da competicao: " << endl;
    data.imprime_data();
}
