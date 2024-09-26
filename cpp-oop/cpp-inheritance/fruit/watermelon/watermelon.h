#include "../fruit.h"

#ifndef WATERMELON_H
#define WATERMELON_H

class Watermelon: private Fruit {
    private:
        double extra_price;
        bool is_season;

    public:
        Watermelon();
        Watermelon(string def_name, double def_extra_price, bool def_is_season);

        void set_extra_price(double new_extra_price);
        double get_extra_price();

        void set_is_season(bool new_is_season);
        bool get_is_season();

        double calculate_final_price();
};

#endif
