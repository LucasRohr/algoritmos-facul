#include <iostream>
#include "./poligono/circulo/circulo.h"

int main() {
    Poligono* poli;

    Poligono poligono;
    Circulo circulo;

    int opcao;
    string nome;
    int vertices;
    int arestas;

    cout << "Digite uma opcao de poligono (1 - Circulo, 2 - Outro)" << endl;
    cin >> opcao;

    if (opcao == 1) {
        double raio;

        cout << "Digite o raio do circulo: " << endl;
        cin >> raio;

        circulo = Circulo(raio);
        poli = &circulo;
    }

    if (opcao == 2) {
        cout << "Digite o nome do poligono: " << endl;
        cin >> nome;

        cout << "Digite o total de arestas do poligono: " << endl;
        cin >> arestas;

        cout << "Digite o total de vertices do poligono: " << endl;
        cin >> vertices;

        poligono = Poligono(nome, arestas, vertices);
        poli = &poligono;
    }

    cout << "Area do poligono: " << poli->calcula_area() << endl;
    cout << "Perimetro do poligono: " << poli->calcula_perimetro() << endl;

    if (Circulo* c = dynamic_cast<Circulo*>(poli)) {
        cout << "Diametro do circulo: " << c->calcula_diametro() << endl;
    }

    return 0;
}
