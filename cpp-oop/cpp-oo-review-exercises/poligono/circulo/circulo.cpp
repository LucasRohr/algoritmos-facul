#include "circulo.h"

#define PI 3.14159
#define NOME_CIRCULO "Circulo"
#define ARESTAS_CIRCULO 1
#define VERTICES_CIRCULO 0

Circulo::Circulo(double def_raio): Poligono(NOME_CIRCULO, ARESTAS_CIRCULO, VERTICES_CIRCULO) {
    raio = def_raio;
}

void Circulo::set_raio(double new_raio) {
    raio = new_raio;
}

double Circulo::get_raio() {
    return raio;
}

double Circulo::calcula_diametro() {
    return raio * 2;
}

double Circulo::calcula_area() {
    return PI * pow(raio, 2);
}

double Circulo::calcula_perimetro() {
    return 2 * PI * raio;
}
