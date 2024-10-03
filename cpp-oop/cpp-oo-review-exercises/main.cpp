#include "./nadador/nadador.h"
#include "./corredor/corredor.h"
#include "./informacoes_atleta/informacoes_atleta.h"

int main() {
    Data data = Data(24, 11, 2024);
    Data data_2 = Data(31, 12, 2024);

    Competicao competicao_1 = Competicao("Correr é show", data);
    Competicao competicao_2 = Competicao("Sao Silvestre", data_2);

    Nadador nadador = Nadador("Cielo", 36, "borboleta");
    Corredor corredor = Corredor("Josenildo", 91, 68, competicao_1);
    Corredor corredor_2 = Corredor("Petrolina", 100, 60, competicao_2);

    cout << "Nome da competicao: " << competicao_1.get_nome() << endl;
    competicao_1.imprime_data();

    cout << endl;

    nadador.imprime_info();

    cout << endl;

    // Alterar data da competicao do corredor
    corredor.get_competicao().set_data(Data(23, data.get_mes(), data.get_ano()));
    corredor.get_competicao().imprime_data();

    cout << endl;

    corredor_2.imprime_info();

    cout << endl;

    // =================

    Atleta* a;
    InformacoesAtleta informacoes_atleta;
    int opcao = 0;

    string nome_input;
    int idade_input;
    string categoria_input;
    double peso_input;
    string nome_competicao_input;

    cout << "Digite uma opcao de criacao de Atleta (1 - Nadador, 2 - Corredor): " << endl;
    cin >> opcao;

    cout << "Digite um nome: " << endl;
    cin >> nome_input;

    cout << "Digite uma idade: " << endl;
    cin >> idade_input;

    if (opcao == 1) {
        Nadador nadador = Nadador();

        cout << "Digite uma categoria: " << endl;
        cin >> categoria_input;

        nadador.set_nome(nome_input);
        nadador.set_idade(idade_input);
        nadador.set_categoria(categoria_input);

        a = &nadador;
    }

    if (opcao == 2) {
        Corredor corredor = Corredor();

        cout << "Digite o peso: " << endl;
        cin >> peso_input;

        cout << "Digite o nome da competicao do corredor: " << endl;
        cin >> nome_competicao_input;

        corredor.set_nome(nome_input);
        corredor.set_idade(idade_input);
        corredor.set_peso(peso_input);
        corredor.set_competicao(Competicao(nome_competicao_input, data));

        a = &corredor;
    }

    cout << "infos antes da alteracao" << endl;

    informacoes_atleta.imprime_exclusivos_atleta(a);
    informacoes_atleta.imprime_informacoes_atleta(a);

    cout << endl;

    if(Nadador* n = dynamic_cast<Nadador*>(a)) {
        n->set_categoria("livre");
    } else if (Corredor* c = dynamic_cast<Corredor*>(a)) {
        c->set_peso(89);
    }

    cout << "infos depois da alteracao" << endl;

    informacoes_atleta.imprime_exclusivos_atleta(a);
    informacoes_atleta.imprime_informacoes_atleta(a);

    return 0;
}