#include <iomanip>
#include "banana.h"

Banana::Banana(): Fruit() {
    type = "";
}

Banana::Banana(string def_name, string def_type): Fruit(def_name) {
    type = def_type;
}

void Banana::set_type(string new_type) {
    type = new_type;
}

string Banana::get_type() {
    return type;
}
