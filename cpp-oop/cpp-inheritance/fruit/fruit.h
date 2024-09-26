#include <iostream>

#ifndef FRUIT_H
#define FRUIT_H

using namespace std;

class Fruit {
    private:
        string name;
        double price;

    public:
        Fruit();
        Fruit(string def_name);

        void set_name(string new_name);
        string get_name();

        void set_price(double new_price);
        double get_price();

        double calculate_price(double tax);
};

#endif
