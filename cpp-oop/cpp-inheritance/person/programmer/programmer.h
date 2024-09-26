#include "../person.h"

#ifndef PROGRAMMER_H
#define PROGRAMMER_H

class Programmer: private Person {
    private:
        string fav_language;

    public:
        Programmer();
        Programmer(string def_name, int def_age, string def_fav_language);

        void set_fav_language(string new_fav_language);
        string get_fav_language();

        void print_data();
};

#endif