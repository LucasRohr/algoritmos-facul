#include <iostream>
#include <iomanip>

#ifndef POLIGONO_H
#define POLIGONO_H

using namespace std;

class Poligono {
    private:
        string nome;
        int arestas;
        int vertices;

    public:
        Poligono() = default;
        Poligono(string def_nome, int def_arestas, int def_vertices);

        virtual void set_nome(string new_nome);
        virtual string get_nome();

        virtual void set_arestas(int new_arestas);
        virtual int get_arestas();

        virtual void set_vertices(int new_vertices);
        virtual int get_vertices();

        virtual double calcula_area();
        virtual double calcula_perimetro();
};

#endif
