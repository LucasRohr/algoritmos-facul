#include <iomanip>
#include "programmer.h"

Programmer::Programmer(): Person() {
    fav_language = "";
}

Programmer::Programmer(string def_name, int def_age, string def_fav_language): Person(def_name, def_age) {
    fav_language = def_fav_language;
}

void Programmer::set_fav_language(string new_fav_language) {
    fav_language = new_fav_language;
}

string Programmer::get_fav_language() {
    return fav_language;
}

void Programmer::print_data() {
    cout << "Programmer data: " << endl;
        
    Person::print_data();

    cout << std::setw(19) << "Favorite language: " << fav_language << endl;
}
