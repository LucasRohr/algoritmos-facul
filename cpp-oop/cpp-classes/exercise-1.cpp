#include <iostream>
#include <iomanip>

using namespace std;

class Retangulo {
    private:
        double base;
        double altura;

    public:
        Retangulo();
        Retangulo(double def_base, double def_altura);

        void setBase(double base);
        double getBase();

        void setAltura(double hight);
        double getAltura();

        double getArea();
};

Retangulo::Retangulo() {
    base = 0;
    altura = 0;
}

Retangulo::Retangulo(double def_base, double def_altura) {
    base = def_base;
    altura = def_altura;
}

void Retangulo::setBase(double new_base) {
    base = new_base;
}

double Retangulo::getBase() {
    return base;
}

void Retangulo::setAltura(double new_altura) {
    altura = new_altura;
}

double Retangulo::getAltura() {
    return altura;
}

double Retangulo::getArea() {
    return (base * altura) / 2;
}

int main() {
    Retangulo retangulo;
    double area;

    retangulo.setBase(10);
    retangulo.setAltura(14);

    area = retangulo.getArea();

    std::cout << "Area do retangulo: " << area << std::endl;

    return 0;
}