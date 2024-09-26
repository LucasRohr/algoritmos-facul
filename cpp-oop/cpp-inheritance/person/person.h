#include <iostream>

#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person {
    private:
        string name;
        int age;

    public:
        Person();
        Person(string def_name, int def_age);

        void set_name(string new_name);
        string get_name();

        void set_age(int new_age);
        int get_age();

        void print_data();
};

#endif
