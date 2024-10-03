#include <iomanip>
#include "./data.h"

Data::Data(int def_dia, int def_mes, int def_ano) {
    dia = def_dia;
    mes = def_mes;
    ano = def_ano;
}

void Data::set_dia(int new_dia) {
    dia = new_dia;
}

int Data::get_dia() {
    return dia;
}

void Data::set_mes(int new_mes) {
    mes = new_mes;
}

int Data::get_mes() {
    return mes;
}

void Data::set_ano(int new_ano) {
    ano = new_ano;
}

int Data::get_ano() {
    return ano;
}

void Data::imprime_data() {
    cout << dia << "/" << mes << "/" << ano << endl;
}
