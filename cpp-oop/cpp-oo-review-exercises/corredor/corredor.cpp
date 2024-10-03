#include <iomanip>
#include "corredor.h"

Corredor::Corredor(
    string def_nome,
    int def_idade,
    double def_peso,
    Competicao def_competicao
): Atleta(def_nome, def_idade)  {
    peso = def_peso;
    competicao = def_competicao;
}

void Corredor::set_peso(double new_peso) {
    peso = new_peso;
}

double Corredor::get_peso() {
    return peso;
}

void Corredor::set_competicao(Competicao new_competicao) {
    competicao = new_competicao;
}

Competicao Corredor::get_competicao() {
    return competicao;
}

void Corredor::imprime_competicao() {
    cout << "Competicao do corredor: " << endl
        << "Nome: " << std::setw(6) << competicao.get_nome() << endl;

    competicao.imprime_data();
}

void Corredor::imprime_info() {
     cout << "== Dados do corredor ==" << endl
        << "Nome: " << std::setw(6) << Atleta::get_nome() << endl
        << "Idade: " << std::setw(7) << Atleta::get_idade() << endl
        << "Peso: " << std::setw(6) << peso << endl;

    imprime_competicao();
}
