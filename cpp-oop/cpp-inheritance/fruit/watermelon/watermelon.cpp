#include <iomanip>
#include "watermelon.h"

Watermelon::Watermelon(): Fruit() {
    extra_price = 0.0;
    is_season = false;
}

Watermelon::Watermelon(string def_name, double def_extra_price, bool def_is_season): Fruit(def_name) {
    extra_price = def_extra_price;
    is_season = def_is_season;
}

void Watermelon::set_extra_price(double new_extra_price) {
    extra_price = new_extra_price;
}

double Watermelon::get_extra_price() {
    return extra_price;
}

void Watermelon::set_is_season(bool new_is_season) {
    is_season = new_is_season;
}

bool Watermelon::get_is_season() {
    return is_season;
}

double Watermelon::calculate_final_price() {
    if(is_season) {
        return Fruit::get_price();
    }

    return Fruit::get_price() + extra_price;
}

