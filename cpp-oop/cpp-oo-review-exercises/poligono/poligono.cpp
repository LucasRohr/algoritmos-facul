#include "poligono.h"

Poligono::Poligono(string def_nome, int def_arestas, int def_vertices) {
    nome = def_nome;
    arestas = def_arestas;
    vertices = def_vertices;
}

void Poligono::set_nome(string new_nome) {
    nome = new_nome;
}

string Poligono::get_nome() {
    return nome;
}

void Poligono::set_arestas(int new_arestas) {
    arestas = new_arestas;
}

int Poligono::get_arestas() {
    return arestas;
}

void Poligono::set_vertices(int new_vertices) {
    vertices = new_vertices;
}

int Poligono::get_vertices() {
    return vertices;
}

double Poligono::calcula_area() {
    return 0;
}

double Poligono::calcula_perimetro() {
    return 0;
}
