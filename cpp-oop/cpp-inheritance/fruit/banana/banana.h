#include "../fruit.h"

#ifndef BANANA_H
#define BANANA_H

class Banana: private Fruit {
    private:
        string type;

    public:
        Banana();
        Banana(string def_name, string def_type);

        void set_type(string new_type);
        string get_type();
};

#endif