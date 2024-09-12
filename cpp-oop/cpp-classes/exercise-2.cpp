#include <iostream>
#include <iomanip>

#define TOTAL_PESSOAS 3

using namespace std;

class Pessoa {
    private:
        string nome;
        int idade;
        double altura;
        int quantidade_irmaos;
        string endereco;

    public:
        Pessoa();

        Pessoa(
            string def_nome,
            int def_idade,
            double def_altura,
            int def_quantidade_irmaos,
            string def_endereco
        );

        void setNome(string new_nome);
        string getNome();

        void setIdade(int new_idade);
        int getIdade();

        void setAltura(double new_altura);
        double getAltura();

        void setQuantidadeIrmaos(int new_quantidade_irmaos);
        int getQuantidadeIrmaos();

        void setEndereco(string new_endereco);
        string getEndereco();

        void imprime_info();
        bool is_filho_unico();
};

Pessoa::Pessoa() {
    nome = "";
    idade = 0;
    altura = 0;
    quantidade_irmaos = 0;
    endereco = "";
}

Pessoa::Pessoa(
    string def_nome,
    int def_idade,
    double def_altura,
    int def_quantidade_irmaos,
    string def_endereco
) {
    nome = def_nome;
    idade = def_idade;
    altura = def_altura;
    quantidade_irmaos = def_quantidade_irmaos;
    endereco = def_endereco;
}

void Pessoa::setNome(string new_nome) {
    nome = new_nome;
}

string Pessoa::getNome() {
    return nome;
}

void Pessoa::setIdade(int new_idade) {
    idade = new_idade;
}

int Pessoa::getIdade() {
    return idade;
}

void Pessoa::setAltura(double new_altura) {
    altura = new_altura;
}

double Pessoa::getAltura() {
    return altura;
}

void Pessoa::setQuantidadeIrmaos(int new_quantidade_irmaos) {
    quantidade_irmaos = new_quantidade_irmaos;
}

int Pessoa::getQuantidadeIrmaos() {
    return quantidade_irmaos;
}

void Pessoa::setEndereco(string new_endereco) {
    endereco = new_endereco;
}

string Pessoa::getEndereco() {
    return endereco;
}

void Pessoa::imprime_info() {
    cout << "Dados da pessoa: " << endl
        << std::setw(10) << "Nome: " << nome << endl
        << std::setw(11) << "Idade: " << idade << endl 
        << std::setw(12) << "Altura: " << altura << endl
        << std::setw(26) << "Quantidade de irmaos: " << quantidade_irmaos << endl
        << std::setw(14) << "Endereco: " << endereco << endl << endl;
}

bool Pessoa::is_filho_unico() {
    return quantidade_irmaos == 0;
}

int main() {
    Pessoa pessoa1 = Pessoa("jorge", 23, 1.75, 2, "rua xablau 324");
    Pessoa pessoa2 = Pessoa("kleyton", 45, 1.56, 0, "rua macarena 1234");
    Pessoa pessoa3 = Pessoa("hella", 78, 1.67, 4, "rua skylab 666");

    Pessoa pessoas[TOTAL_PESSOAS] = {pessoa1, pessoa2, pessoa3};

    for (int i = 0; i < TOTAL_PESSOAS; i++) {
        pessoas[i].imprime_info();

        if (pessoas[i].is_filho_unico()) {
            cout << "Filho(a) unico(a)" << endl << endl;
        } else {
            cout << "Nao eh filho(a) unico(a)" << endl << endl;
        }
    }

    return 0;
}