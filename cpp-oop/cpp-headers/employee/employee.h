#include <iostream>
#include "../calculator/calculator.h"

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;

class Employee {
    private:
        string name;
        string address;
        Calculator calculator;

    public:
        Employee();

        Employee(
            string def_name,
            string def_address,
            Calculator def_calculator
        );

        void setName(string new_name);
        string getName();

        void setAddress(string new_address);
        string getAddress();

        void setCalculator(Calculator new_calculator);
        Calculator getCalculator();

        float sum(float value_1, float value_2);
        float subtract(float value_1, float value_2);
        float multiply(float value_1, float value_2);
        float divide(float value_1, float value_2);

        int square(int value);
        int cube(int value);

        void print_info();
};

#endif
