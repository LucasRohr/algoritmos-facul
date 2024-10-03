#include <iomanip>
#include "nadador.h"

Nadador::Nadador(string def_nome, int def_idade, string def_categoria): Atleta(def_nome, def_idade) {
    categoria = def_categoria;
}

void Nadador::set_categoria(string new_categoria) {
    categoria = new_categoria;
}

string Nadador::get_categoria() {
    return categoria;
}

void Nadador::imprime_info() {
    Atleta::imprime_info();

    cout << "Categoria: " << std::setw(11) << categoria << endl;
}
