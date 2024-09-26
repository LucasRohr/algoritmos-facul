
#include <iomanip>
#include "person.h"

Person::Person() {
    name = "";
    age = 0;
}

Person::Person(string def_name, int def_age) {
    name = def_name;
    age = def_age;
}

void Person::set_name(string new_name) {
    name = new_name;
}

string Person::get_name() {
    return name;
}

void Person::set_age(int new_age) {
    age = new_age;
}

int Person::get_age() {
    return age;
}

void Person::print_data() {
    cout << "Person data: " << endl
        << std::setw(6) << "Name: " << name << endl
        << std::setw(5) << "Age: " << age << endl << endl;
}
