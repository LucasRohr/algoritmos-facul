#include <iostream>
#include <iomanip>

#define TOTAL_BANDAS 2

using namespace std;

class Banda {
    private:
        string nome;
        int total_membros;
        string genero;
        bool is_boa;

    public:
        Banda();

        Banda(
            string def_nome,
            int def_total_membros,
            string def_genero,
            bool def_is_boa
        );

        void setNome(string new_nome);
        string getNome();

        void setTotalMembros(int new_total_membros);
        int getTotalMembros();

        void setGenero(string new_genero);
        string getGenero();

        void setIsBoa(bool new_is_boa);
        bool getIsBoa();

        void imprime_banda();
};

Banda::Banda() {
    nome = "";
    total_membros = 0;
    genero = "";
    is_boa = false;
}

Banda::Banda(
    string def_nome,
    int def_total_membros,
    string def_genero,
    bool def_is_boa
) {
    nome = def_nome;
    total_membros = def_total_membros;
    genero = def_genero;
    is_boa = def_is_boa;
}

void Banda::setNome(string new_nome) {
    nome = new_nome;
}

string Banda::getNome() {
    return nome;
}

void Banda::setTotalMembros(int new_total_membros) {
    total_membros = new_total_membros;
}

int Banda::getTotalMembros() {
    return total_membros;
}

void Banda::setGenero(string new_genero) {
    genero = new_genero;
}

string Banda::getGenero() {
    return genero;
}

void Banda::setIsBoa(bool new_is_boa) {
    is_boa = new_is_boa;
}

bool Banda::getIsBoa() {
    return is_boa;
}

void Banda::imprime_banda() {
    cout << "Dados da banda: " << endl
        << std::setw(10) << "Nome: " << nome << endl
        << std::setw(22) << "Total de membros: " << total_membros << endl 
        << std::setw(12) << "Genero: " << genero << endl
        << std::setw(14) << "Eh buena? " << (is_boa ? "Sim!" : "Nao!") << endl << endl;
}

int main() {
    Banda banda1 = Banda("Green Day", 3, "Punk Rock", true);
    Banda banda2 = Banda("Oasis", 5, "Indie meio triste", false);

    Banda bandas[TOTAL_BANDAS] = {banda1, banda2};

    for (int i = 0; i < TOTAL_BANDAS; i++) {
        bandas[i].imprime_banda();
    }

    return 0;
}