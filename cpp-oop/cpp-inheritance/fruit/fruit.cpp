
#include <iomanip>
#include "fruit.h"

Fruit::Fruit() {
    name = "";
    price = 0.0;
}

Fruit::Fruit(string def_name) {
    name = def_name;
    price = 0.0;
}

void Fruit::set_name(string new_name) {
    name = new_name;
}

string Fruit::get_name() {
    return name;
}

void Fruit::set_price(double new_price) {
    price = new_price;
}

double Fruit::get_price() {
    return price;
}

double Fruit::calculate_price(double tax) {
    return price + (price * tax);
}
