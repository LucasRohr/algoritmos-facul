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

        virtual void set_name(string new_name);
        virtual string get_name();

        virtual void set_age(int new_age);
        virtual int get_age();

        virtual void print_data();
};

#endif
