#include <iostream>
#include <iomanip>
#include "../poligono.h"

#ifndef CIRCULO_H
#define CIRCULO_H

using namespace std;

class Circulo: public Poligono {
    private:
        double raio;

    public:
        Circulo() = default;
        Circulo(double def_raio);

        void set_raio(double new_raio);
        double get_raio();

        double calcula_diametro();

        double calcula_area();
        double calcula_perimetro();
};

#endif
